#include "../inc/hellman.h"

using namespace std;

//Функция проверки число на простоту
bool simplecheck(int argument_p)
{
    int quotient;
    for (int i = 2; i < argument_p; i++) 
    {
        if (argument_p % i == 0 && argument_p == i)
        {
            return false;
        }
    }
    return true;
};

//Определение исходных данных
data resolving(data Input)
{
    srand(time(NULL));
    int Q;
    Q = (100 + rand() % 400);
    Input.argument_p = 2 * Q + 1;
    while (!simplecheck(Input.argument_p))
    {
        while (!simplecheck(Q))
        {
            Q = (100 + rand() % 400);
        }
        Input.argument_p = 2 * Q + 1;
    }
    Input.argument_g = (100 + rand() % Input.argument_p - 1);
    while (!(fastpow(Input.argument_g, Q, Input.argument_p) != 1) && (Input.argument_g < Input.argument_p - 1) && (Input.argument_g > 0))
    {
        Input.argument_g = (100 + rand() % Input.argument_p - 1);
    }
    Input.Xa = (100 + rand() % Input.argument_p)* 2;
    Input.Xb = (100 + rand() % Input.argument_p)* 2;

    while(Input.Xa == Input.Xb)
    {
        cout << "[VALIDATION]: key Xa == Xb, rerandomize" << endl;
        Input.Xb = (100 + rand() % Input.argument_p) * 2;
    }

    Input.Ya = fastpow(Input.argument_g,Input.Xa,Input.argument_p);
    Input.Yb = fastpow(Input.argument_g,Input.Xb,Input.argument_p);

    Input.Za = fastpow(Input.Yb,Input.Xa,Input.argument_p);
    Input.Zb = fastpow(Input.Ya,Input.Xb,Input.argument_p);

    return Input;
}
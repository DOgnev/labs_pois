#include "../inc/resolve.h"

using namespace std;

bool DEBUG_RESOLVE = false;
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

int random (int delta)
{
    int Q;
    srand(time(0));
    Q = delta / 10 + (rand()%delta);
    while(!simplecheck(Q))
    {
        Q = delta / 10 + (rand()%delta);
    }
    return Q;
}

//Определение исходных данных
data resolving(data Input)
{
    int Q;
    Input.argument_p = 4;
    while (!simplecheck(Input.argument_p))
    {
        {
            Q = random(200);
        }
        Input.argument_p = 2 * Q + 1;
    }
    Input.argument_g = random(Input.argument_p - 1);
    while (!(fastpow(Input.argument_g, Q, Input.argument_p) != 1) && (Input.argument_g < Input.argument_p - 1) && (Input.argument_g > 0))
    {
        Input.argument_g = random(Input.argument_p - 1);
    }
    Input.X = (100 + rand() % Input.argument_p - 1);
    while (!(Input.X < Input.argument_p))
    {
        Input.X = random(Input.argument_p - 1);
    }

    Input.Y = fastpow(Input.argument_g, Input.X, Input.argument_p);
    Input.K = random(Input.argument_p - 1);
    while (!(Input.K < Input.argument_p))
    {
        Input.K = random(Input.argument_p - 1);
    }
    if (DEBUG_RESOLVE == true)
    {
        cout << "[DEBUG_RESOLVE]: P = " << Input.argument_p << endl;
        cout << "[DEBUG_RESOLVE]: G = " << Input.argument_g << endl;
        cout << "[DEBUG_RESOLVE]: X = " << Input.X << endl;
        cout << "[DEBUG_RESOLVE]: Y = " << Input.Y << endl;
        cout << "[DEBUG_RESOLVE]: K = " << Input.K << endl;
    }
    return Input;
}
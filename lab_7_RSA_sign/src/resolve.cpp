#include "../inc/resolve.h"

bool DEBUG_RESOLVE = false;
//Функция проверки число на простоту
bool simplecheck(int argument_p)
{
    int quotient;
    for (int i = 2; i < argument_p; i++) 
    {
        if (argument_p % i == 0)
        {
            return false;
        }
    }
    return true;
};

int random (int delta)
{
    mt19937 gen(time(0));
    uniform_int_distribution<> dist(delta/2,delta);
    int Q = 4;
    while(!simplecheck(Q))
    {
        Q = dist(gen);
    }
    return Q;
}

//Определение исходных данных
data resolving(data Input, int delta)
{
    
    while (!(Input.D > 1))
    {
        Input = {4,4,1,1,1,1};
        ext_nod_exit Invertion;
        Input.argument_p = 4;
        while (!simplecheck(Input.argument_p))
        {
            {
                Input.argument_q = random(delta);
            }
            Input.argument_p = 2 * Input.argument_q + 1;
        }
        Input.N = Input.argument_p * Input.argument_q;
        Input.phi = ((Input.argument_p - 1) * (Input.argument_q - 1));

        while (!( (Invertion.NOD == 1) && (Input.C < Input.phi) && (Input.C > 0)))
        {
            Input.C = random(Input.phi);
            Invertion = ext_nod(Input.phi, Input.C);
        }
            Input.D = Invertion.y < 0 ? (Invertion.y + Input.phi) : Invertion.y;
        }
    if (DEBUG_RESOLVE == true)
    {
        cout << "[DEBUG_RESOLVE]: P = " << Input.argument_p << endl;
        cout << "[DEBUG_RESOLVE]: Q = " << Input.argument_q << endl;
        cout << "[DEBUG_RESOLVE]: N= " << Input.N << endl;
        cout << "[DEBUG_RESOLVE]: phi = " << Input.phi << endl;
        cout << "[DEBUG_RESOLVE]: C = " << Input.C << endl;
        cout << "[DEBUG_RESOLVE]: D = " << Input.D << endl;
    }
    return Input;
}
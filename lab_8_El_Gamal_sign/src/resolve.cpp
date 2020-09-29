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
    uniform_int_distribution<> dist(4,delta);
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
    
    while (!(Input.K_inv > 1))
    {
        Input = {4,4,1,1,1,1,1};
        ext_nod_exit Invertion;
        Input.argument_p = 4;
        while (!simplecheck(Input.argument_p))
        {
            {
                Input.argument_q = random(delta);
            }
            Input.argument_p = 2 * Input.argument_q + 1;
        }
        Input.G = random(Input.argument_p - 1);
        while (!(fastpow(Input.G, Input.argument_q, Input.argument_p) != 1) && (Input.G < Input.argument_p - 1) && (Input.G > 0))
        {
            Input.G = random(Input.argument_p - 1);
        }
        Input.X = random(Input.argument_p);
        while (!(Input.X < Input.argument_p))
        {
        Input.X = random(Input.argument_p);
        }
        Input.Y = fastpow(Input.G, Input.X, Input.argument_p);
        Input.K = random(Input.argument_p - 1);
        while (!( (Invertion.NOD == 1) && (Input.K < Input.argument_p-1) && (Input.K > 0)))
        {
            Input.K = random(Input.argument_p-1);
            Invertion = ext_nod(Input.argument_p-1, Input.K);
        }
        Input.K_inv = Invertion.y < 0 ? (Invertion.y + Input.argument_p-1) : Invertion.y;
    }
    if (DEBUG_RESOLVE == true)
    {
        cout << "[DEBUG_RESOLVE]: P = " << Input.argument_p << endl;
        cout << "[DEBUG_RESOLVE]: Q = " << Input.argument_q << endl;
        cout << "[DEBUG_RESOLVE]: G= " << Input.G << endl;
        cout << "[DEBUG_RESOLVE]: X = " << Input.X << endl;
        cout << "[DEBUG_RESOLVE]: Y = " << Input.Y << endl;
        cout << "[DEBUG_RESOLVE]: K = " << Input.K << endl;
        cout << "[DEBUG_RESOLVE]: K_inv = " << Input.K_inv << endl;
    }
    return Input;
}
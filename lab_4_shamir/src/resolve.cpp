#include "../inc/resolve.h"

bool DEBUG_RESOLVE = true;
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
    
    while (!((Input.Da > 1) && (Input.Db > 1)))
    {
        int Q;
        ext_nod_exit Invertion_a, Invertion_b;
        Input.argument_p = 4;
        while (!simplecheck(Input.argument_p))
        {
            {
                Q = random(500);
            }
            Input.argument_p = 2 * Q + 1;
        }
        Input.Ca = 0;
        Input.Cb = 0;

        while (!((Input.Ca != Input.Cb) && (Invertion_a.NOD == 1) && (Invertion_b.NOD == 1) && (Input.Ca < Input.argument_p - 1) && (Input.Cb < Input.argument_p - 1) && (Input.Ca > 0) && (Input.Cb > 0)))
        {
            Input.Ca = random(Input.argument_p - 1);
            Input.Cb = random(Input.argument_p - 1);
            Invertion_a = ext_nod(Input.argument_p - 1, Input.Ca);
            Invertion_b = ext_nod(Input.argument_p - 1, Input.Cb);
        }
            Input.Da = Invertion_a.y < 0 ? (Invertion_a.y + (Input.argument_p - 1)) : Invertion_a.y;
            Input.Db = Invertion_b.y < 0 ? (Invertion_b.y + (Input.argument_p - 1)) : Invertion_b.y;
        }
    if (DEBUG_RESOLVE == true)
    {
        cout << "[DEBUG_RESOLVE]: P = " << Input.argument_p << endl;
        cout << "[DEBUG_RESOLVE]: Ca = " << Input.Ca << endl;
        cout << "[DEBUG_RESOLVE]: Cb = " << Input.Cb << endl;
        cout << "[DEBUG_RESOLVE]: Da = " << Input.Da << endl;
        cout << "[DEBUG_RESOLVE]: Db = " << Input.Db << endl;
    }
    return Input;
}
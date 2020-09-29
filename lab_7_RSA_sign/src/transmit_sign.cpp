#include "../inc/transmit_sign.h"

bool DEBUG_TRANSMIT_SIGN = false;

int search_divisor(int Number)
{
    for (int i = 2; i < ceil(sqrt(Number)); i++)
    {
        if ((Number % i) == 0)
        {
            return i;
        }
    }
    return Number;
}

void transmit_sign(int Message)
{   
    data Input_sign = {4,4,1,1,1,1};
    Input_sign = resolving(Input_sign, 50);
    int KEY = 13;
    int S1 = 1, Sign = 1, Sign_res = 1;
    cout << "[transmit]: Transmiting SIGN" << endl;
    Sign = get_sign(Message, KEY);
    int tmp = Sign, divisor = 1;
    while (!(tmp == 0))
    {
        divisor = 1;
        if (tmp < Input_sign.N)
        {
            cout << "[transmit]: Transmiting LAST SIGN PART from A to B" << endl;
            S1 = fastpow(tmp, Input_sign.D, Input_sign.N);
            cout << "[transmit]: Resolving SIGN" << endl;
            int w = fastpow(S1, Input_sign.C, Input_sign.N);
            Sign_res *= w;
            tmp /= Input_sign.N;
        } else if (tmp >= Input_sign.N)
        {
            divisor = search_divisor(tmp);
            if (divisor == tmp)
            {
                Input_sign = {4,4,1,1,1,1};
                Input_sign = resolving(Input_sign, tmp);
                divisor = 1;
            } else {
                tmp /= divisor;
                cout << "[transmit]: Transmiting SIGN PART from A to B" << endl;
                S1 = fastpow(divisor, Input_sign.D, Input_sign.N);
                int w = fastpow(S1, Input_sign.C, Input_sign.N);
                Sign_res *= w;
            }
        }

        if (DEBUG_TRANSMIT_SIGN == true)
        {
            cout << "[DEBUG transmit SIGN]: Mess= " << Message << endl;
            cout << "[DEBUG transmit SIGN]: Sign= " << Sign << endl;
            cout << "[DEBUG transmit SIGN]: Divisor= " << divisor << endl;
            cout << "[DEBUG transmit SIGN]: Tmp= " << tmp << endl;
            cout << "[DEBUG transmit SIGN]: S1 = " << S1<< endl;
            cout << "[DEBUG transmit SIGN]: Sign_res= " << Sign_res << endl;
        }
    }
    if (Sign_res == Sign)
    {
        cout << "Sign transmit Succesfull" << endl;
    } else 
    {
        cout << "Sign transmit Failled" << endl;
    }
}
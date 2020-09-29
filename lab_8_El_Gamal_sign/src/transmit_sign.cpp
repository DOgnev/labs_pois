#include "../inc/transmit_sign.h"

bool DEBUG_TRANSMIT_SIGN = true;

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

void transmit_sign(string Message)
{   
    data Input_sign = {4,4,1,1,1,1};
    Input_sign = resolving(Input_sign, 50);
    int KEY = 13;
    int S1 = 1, S2 = 1, Sign = 1, Sign_res = 1, w = 1;
    cout << "[transmit]: Transmiting SIGN" << endl;
    Sign = get_sign(Message, KEY);
    int tmp = Sign, divisor = 1;
    cout << "[DEBUG transmit SIGN]: Sign= " << Sign << endl;
    while (!(tmp == 0))
    {
        divisor = 1;
        if (tmp < Input_sign.argument_p)
        {
            cout << "[transmit]: Transmiting LAST SIGN PART from A to B" << endl;
            S1 = fastpow(Input_sign.G, Input_sign.K, Input_sign.argument_p);
            S2 = ((tmp - Input_sign.X * S1) * Input_sign.K_inv) % (Input_sign.argument_p - 1);
            cout << "[DEBUG transmit SIGN]: S2= " << S2 << endl;
            S2 = S2 < 0 ? S2 + Input_sign.argument_p - 1 : S2;
            cout << "[DEBUG transmit SIGN]: S2= " << S2 << endl;
            cout << "[transmit]: Resolving SIGN" << endl;
            Sign_res = (fastpow(Input_sign.Y,S1,Input_sign.argument_p) * fastpow(S1,S2,Input_sign.argument_p)) % Input_sign.argument_p;
            w = fastpow(Input_sign.G,tmp,Input_sign.argument_p);
            if (Sign_res == w)
            {
                cout << "SIGN transmit success" << endl;
            } else {
                cout << "SIGN transmit failed" << endl;
                if (DEBUG_TRANSMIT_SIGN == true)
                {
                    cout << "[DEBUG transmit SIGN]: Mess= " << Message << endl;
                    cout << "[DEBUG transmit SIGN]: Sign= " << Sign << endl;
                    cout << "[DEBUG transmit SIGN]: Divisor= " << divisor << endl;
                    cout << "[DEBUG transmit SIGN]: Tmp= " << tmp << endl;
                    cout << "[DEBUG transmit SIGN]: S1 = " << S1<< endl;
                    cout << "[DEBUG transmit SIGN]: S2 = " << S2<< endl;
                    cout << "[DEBUG transmit SIGN]: Sign_res= " << Sign_res << endl;
                    cout << "[DEBUG transmit SIGN]: w= " << w << endl;
                    cout << "[DEBUG transmit SIGN]: P= " << Input_sign.argument_p << endl;
                }
            }
            tmp /= Input_sign.argument_p;
        } else if (tmp >= Input_sign.argument_p)
        {
            divisor = search_divisor(tmp);
            if (divisor == tmp)
            {
                Input_sign = {4,4,1,1,1,1};
                Input_sign = resolving(Input_sign, tmp*2);
                divisor = 1;
            } else {
                tmp /= divisor;
                cout << "[transmit]: Transmiting SIGN PART from A to B" << endl;
                S1 = fastpow(Input_sign.G, Input_sign.K, Input_sign.argument_p);
                S2 = ((divisor - Input_sign.X * S1) * Input_sign.K_inv) % (Input_sign.argument_p - 1);
                S2 = S2 < 0 ? S2 + Input_sign.argument_p - 1 : S2;
                cout << "[transmit]: Resolving SIGN" << endl;
                Sign_res = (fastpow(Input_sign.Y,S1,Input_sign.argument_p) * fastpow(S1,S2,Input_sign.argument_p)) % Input_sign.argument_p;
                w = fastpow(Input_sign.G,divisor,Input_sign.argument_p);
                if (Sign_res == w)
                {
                    cout << "SIGN transmit success" << endl;
                } else {
                    cout << "SIGN transmit failed" << endl;
                    if (DEBUG_TRANSMIT_SIGN == true)
                    {
                        cout << "[DEBUG transmit SIGN]: Mess= " << Message << endl;
                        cout << "[DEBUG transmit SIGN]: Sign= " << Sign << endl;
                        cout << "[DEBUG transmit SIGN]: Divisor= " << divisor << endl;
                        cout << "[DEBUG transmit SIGN]: Tmp= " << tmp << endl;
                        cout << "[DEBUG transmit SIGN]: S1 = " << S1<< endl;
                        cout << "[DEBUG transmit SIGN]: S2 = " << S2<< endl;
                        cout << "[DEBUG transmit SIGN]: Sign_res= " << Sign_res << endl;
                        cout << "[DEBUG transmit SIGN]: w= " << w << endl;
                    }
                }
            }
        }
    }
}
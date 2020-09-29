#include "../inc/transmit.h"

bool DEBUG_TRANSMIT = false;

int transmit(int Message, data Input)
{
    while(true)
    {
        int A = 1, B = 1, M = 1;
        A = fastpow(Input.argument_g, Input.K, Input.argument_p);
        B = Message * fastpow(Input.Y, Input.K, Input.argument_p);
        cout << "A and B solved, transmiting message" << endl;
        M = B * fastpow(A,(Input.argument_p - 1 - Input.X), Input.argument_p);
        if (DEBUG_TRANSMIT == true)
        {
            cout << "[DEBUG transmit]: Mess= " << Message << endl;
            cout << "[DEBUG transmit]: A= " << A << endl;
            cout << "[DEBUG transmit]: B= " << B << endl;
            cout << "[DEBUG transmit]: M= " << M << endl;
        }
        if (M = Message)
        {
            cout << "Transmiting success" << endl;
            return M;
        } else
        {   
            cout << "Transmiting Failed" << endl;
            resolving (Input);
        }
    }
}
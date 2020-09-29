#include "../inc/transmit.h"

bool DEBUG_TRANSMIT = true;

int transmit(int Message, data Input)
{
    int Message_res, X1;
    while(true)
    {
        cout << "[transmit]: Transmiting from A to B " << endl;
        X1 = fastpow(Message, Input.D, Input.N);
        cout << "[transmit]: Resolving message" << endl;
        Message_res = fastpow(X1, Input.C, Input.N);
        if (DEBUG_TRANSMIT == true)
        {
            cout << "[DEBUG transmit]: Mess= " << Message << endl;
            cout << "[DEBUG transmit]: X1= " << X1 << endl;
            cout << "[DEBUG transmit]: Mess_res= " << Message_res << endl;
        }
        if (Message_res == Message)
        {
            cout << "Transmit Succesfull" << endl;
            return Message_res;
        } else {
            cout << "Transmit failed" << endl;
            Input = resolving(Input);
        }
    }
}
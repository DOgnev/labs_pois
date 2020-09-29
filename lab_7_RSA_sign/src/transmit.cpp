#include "../inc/transmit.h"
#include "../inc/transmit_sign.h"

bool DEBUG_TRANSMIT = false;

int transmit(int Message, data Input)
{
    int Message_res = 1, X1 = 1;
    while(true)
    {
        Input = resolving(Input, 50);
        Message_res = 1, 
        X1 = 1;
        cout << "[transmit]: Transmiting from A to B " << endl;
        X1 = fastpow(Message, Input.D, Input.N);
        cout << "[transmit]: Transmiting SIGN from A to B" << endl;
        transmit_sign(Message);
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
        }
    }
}
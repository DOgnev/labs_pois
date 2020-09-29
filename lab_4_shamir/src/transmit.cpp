#include "../inc/transmit.h"

bool DEBUG_TRANSMIT = true;

int transmit(int Message, data Input)
{
    int X1, X2, X3, X4;
    while(true)
    {
        X1 = fastpow(Message, Input.Ca, Input.argument_p);
        X2 = fastpow(X1, Input.Cb, Input.argument_p);
        X3 = fastpow(X2, Input.Da, Input.argument_p);
        X4 = fastpow(X3, Input.Db, Input.argument_p);
        
        cout << "Transmitting A to B [itter 1]. X1: "<< X1 << endl;
        cout << "Transmitting B to A [itter 2]. X2: "<< X2 << endl;
        cout << "Transmitting A to B [itter 3]. X3: "<< X3 << endl;
        cout << "Solve message [itter 4]. X4: "<< X4 << endl;

        if (DEBUG_TRANSMIT == true)
        {
            cout << "[DEBUG transmit]: Mess= " << Message << endl;
            cout << "[DEBUG transmit]: X1= " << X1 << endl;
            cout << "[DEBUG transmit]: X2= " << X2 << endl;
            cout << "[DEBUG transmit]: X3= " << X3 << endl;
            cout << "[DEBUG transmit]: X4= " << X4 << endl;
        }

        if (X4 == Message)
        {
            cout << "Transmit Succesfull" << endl;
            return X4;
        } else {
            cout << "Transmit failed" << endl;
              Input = resolving (Input);
        }
    }

}
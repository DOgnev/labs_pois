#include "../inc/transmit.h"
#include "../inc/transmit_sign.h"
#include "../inc/encrypt_and_decrypt.h"

int main()
{
    data Input = {1,1,1,1,1,1};
    Input = resolving(Input,50);
    string Message = "", Output = "Output = ";
    cout << "Enter message" << endl;
    cin >> Message;
    transmit_sign(Message);
    for (int i = 0; i < Message.length(); i++)
    {
        Output += decrypt(transmit(encrypt(Message[i]),Input));
    }
    cout << "Transmition success = " << Output <<endl;
    system("pause");
    return 0;
}
#include "../inc/transmit.h"
#include "../inc/encrypt_and_decrypt.h"

int main()
{
    data Input;
    string Message, Output = "Output = ";
    Input = resolving(Input);
    cout << "Enter message" << endl;
    cin >> Message;
    for (int i = 0; i < Message.length(); i++)
    {
        Output += decrypt(transmit(encrypt(Message[i]),Input));
    }
    cout << "Transmition success = " << Output <<endl;
    system("pause");
    return 0;
}
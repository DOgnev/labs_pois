#include "../inc/transmit.h"
#include "../inc/encrypt_and_decrypt.h"

int main()
{
    data Input = {1,1,1,1,1};
    Input = resolving(Input);
    string Message = "", Output = "Output = ";
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
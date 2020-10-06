#include "../inc/transmit.h"
#include "../inc/transmit_sign.h"
#include "../inc/encrypt_and_decrypt.h"

int main()
{
    data input;
    input = resolve(input, 500);
    string message = "", output = "Output = ";
    cout << "[MAIN]: Enter message." << endl;
    cin >> message;
    for (int counter = 0; counter < message.length(); counter++)
    {
        output += decrypt(transmit(encrypt(message[counter]), input));
    }
    transmit_sign(message);
    cout << "[MAIN]: Transmition success " << output <<endl;
    system("pause");
    return 0;
}
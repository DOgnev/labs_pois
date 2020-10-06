#include "../inc/transmit.h"
#include "../inc/encrypt_and_decrypt.h"

int main()
{
    data input = {1,1,1,1,1};
    input = resolve(input);
    string message = "", output = "Output = ";
    cout << "[MAIN]: Enter message." << endl;
    cin >> message;
    for (int counter = 0; counter < message.length(); counter++)
    {
        output += decrypt(transmit(encrypt(message[counter]),input));
    }
    cout << "[MAIN]: Transmition success = " << output <<endl;
    system("pause");
    return 0;
}
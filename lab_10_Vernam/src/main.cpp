#include "../inc/transmit.h"
int main()
{
    transmiting_data input;
    string resived_message;
    cout << "[MAIN]: Enter Message." << endl;
    cin >> input.message;
    cout << "[MAIN]: Transmiting." << endl;
    input.key = prevalidation(input.message.length());
    cout << "[MAIN]: key: " << input.key << endl;
    input = solve_encrypt(input);
    cout << "[MAIN]: encrypt: " << input.encrypt << endl;
    resived_message = solve_message(input);
    if (resived_message == input.message)
    {
        cout << "[MAIN]: Transmiting success." << endl;
    } else 
    {
        cout << "[MAIN]: Transmiting failed." << endl;
    }
    cout << "[MAIN]: Transmited message: " << input.message << endl;
    cout << "[MAIN]: Recived message: " << resived_message << endl; 
    system("pause");
    return 0;
}
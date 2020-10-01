#include "../inc/transmit.h"
int main()
{
    transmiting_data Input;
    string resived_message;
    cout << "Enter Message" << endl;
    cin >> Input.MESSAGE;
    cout << "Transmiting" << endl;
    Input.KEY = sequence_creator(Input.MESSAGE.length());
    cout << "KEY: " << Input.KEY << endl;
    Input = solve_encrypt(Input);
    cout << "ENCRYPT: " << Input.ENCRYPT << endl;
    resived_message = solve_message(Input);
    if (resived_message == Input.MESSAGE)
    {
        cout << "Transmiting success" << endl;
    } else 
    {
        cout << "Transmiting failed" << endl;
    }
    cout << "Transmited message: " << Input.MESSAGE << endl;
    cout << "Recived message: " << resived_message << endl; 
    system("pause");
    return 0;
}
#include "../inc/parse_input.h"

int main()
{
    string trd_message, rcd_message;
    cout << "[MAIN] Waiting for message. *HINT: symbols: \'$\', \'!\', \' \' are banned" << endl;
    cin >> trd_message;
    rcd_message = parse_input_block(trd_message);
    cout << "[MAIN] Message recieved successfull: " << rcd_message << ", comparing." << endl;
   if (strcmp(rcd_message.c_str(),trd_message.c_str()) == 0)
    {
        cout << "[MAIN] Transmiting success." << endl;
    } else {
        cout << "[MAIN] Transmiting failed." << endl;
    }
}
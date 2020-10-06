#include "../inc/transmit.h"
#include "../inc/transmit_sign.h"

bool DEBUG_TRANSMIT = false;

int transmit(int message, data input)
{
    int message_res = 1, step_1 = 1;
    while(true)
    {
        input = resolve(input, 50);
        message_res = 1, 
        step_1 = 1;
        cout << "[TRANSMIT]: Transmiting from A to B." << endl;
        step_1 = fastpow(message, input.D, input.N); //Заворчиваем сообщение на передачу
        cout << "[TRANSMIT]: Transmiting SIGN from A to B." << endl;
        transmit_sign(message); //Передаем подпись сообщения
        cout << "[TRANSMIT]: Resolving message." << endl;
        message_res = fastpow(step_1, input.C, input.N); // Разворачиваем сообщения на приёме
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        (DEBUG_TRANSMIT == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: message: " << message << endl : cout << "";
        (DEBUG_TRANSMIT == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: step_1 " << step_1 << endl : cout << "";
        (DEBUG_TRANSMIT == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: message_res: " << message_res << endl : cout << "";
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        if (message_res == message)
        {
            cout << "[TRANSMIT]: Transmit Succesfull." << endl;
            return message_res;
        } else {
            cout << "[TRANSMIT]: Transmit failed." << endl;
        }
    }
}
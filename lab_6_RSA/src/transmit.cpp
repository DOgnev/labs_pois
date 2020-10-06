#include "../inc/transmit.h"

bool DEBUG_TRANSMIT = true;

int transmit(int message, data input)
{
    int message_res, step_1;
    while(true)
    {
        cout << "[TRANSMIT]: Transmiting from A to B." << endl;
        //Вычисляем промежуток для передачи
        step_1 = fastpow(message, input.D, input.N);
        cout << "[TRANSMIT]: Resolving message." << endl;
        //Вычисляем сообщение
        message_res = fastpow(step_1, input.C, input.N);
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        (DEBUG_TRANSMIT == true) ? cout << "[DEBUG|TRANSMIT]: message: " << message << endl : cout << "";
        (DEBUG_TRANSMIT == true) ? cout << "[DEBUG|TRANSMIT]: step_1: " << step_1 << endl : cout << "";
        (DEBUG_TRANSMIT == true) ? cout << "[DEBUG|TRANSMIT]: message_res: " << message_res << endl : cout << "";
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        if (message_res == message)
        {
            cout << "[TRANSMIT]: Transmit Succesfull." << endl;
            return message_res;
        } else {
            cout << "[TRANSMIT]: Transmit failed." << endl;
            input = resolve(input);
        }
    }
}
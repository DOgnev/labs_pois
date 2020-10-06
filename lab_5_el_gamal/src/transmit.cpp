#include "../inc/transmit.h"

bool DEBUG_TRANSMIT = false;

int transmit(int message, data input)
{
    while(true)
    {
        int A = 1, B = 1, message_res = 1;
        //Вычисляем пару для передачи (A,B)
        A = fastpow(input.base, input.K, input.divisor);
        B = message * fastpow(input.Y, input.K, input.divisor);
        cout << "[TRANSMIT]: A and B solved, transmiting message" << endl;
        //Вычисляем сообщение
        message_res = B * fastpow(A,(input.divisor - 1 - input.X), input.divisor);
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        (DEBUG_TRANSMIT == true) ? cout << "[DEBUG|TRANSMIT]: message: " << message << endl : cout << "";
        (DEBUG_TRANSMIT == true) ? cout << "[DEBUG|TRANSMIT]: A: " << A << endl : cout << "";
        (DEBUG_TRANSMIT == true) ? cout << "[DEBUG|TRANSMIT]: B: " << B << endl : cout << "";
        (DEBUG_TRANSMIT == true) ? cout << "[DEBUG|TRANSMIT]: message_res " << message_res << endl : cout << "";
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        if (message_res = message)
        {
            cout << "[TRANSMIT]: Transmiting success" << endl;
            return message_res;
        } else
        {   
            cout << "[TRANSMIT]: Transmiting failed" << endl;
            resolve(input);
        }
    }
}
#include "../inc/transmit_sign.h"

bool DEBUG_TRANSMIT_SIGN = true;

int search_divisor(int number)
{
    for (int counter = 2; counter < ceil(sqrt(number)); counter++)
    {
        if ((number % counter) == 0)
        {
            return counter;
        }
    }
    return number;
}

void transmit_sign(string message)
{   
    data input_sign = {4,4,1,1,1,1};
    input_sign = resolve(input_sign, 50);
    int key = 13; // Масштаб подписи
    int step_1 = 1, sign = 1, sign_res = 1;
    cout << "[TRANSMIT_SIGN]: Transmiting SIGN." << endl;
    sign = get_sign(message, key); // Получаем подпись по переданному сообщению.
    int tmp = sign, divisor = 1;
    while (!(tmp == 0))
    {
        divisor = 1;
        if (tmp < input_sign.N)
        {
            cout << "[TRANSMIT_SIGN]: Transmiting LAST SIGN PART from A to B." << endl;
            step_1 = fastpow(tmp, input_sign.D, input_sign.N); //Заворачиваеим подпись на передаче
            cout << "[TRANSMIT_SIGN]: Resolving SIGN." << endl;
            int step_2 = fastpow(step_1, input_sign.C, input_sign.N); //Разворачиваем подпись на приёме
            sign_res *= step_2;
            tmp /= input_sign.N;
            (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: N: " << input_sign.N << endl : cout << "";

        } else if (tmp >= input_sign.N)
        {
            //Ищем делитель для передачи
            divisor = search_divisor(tmp);
            //Если вдруг делитель целый, то пересчитываем коэффициенты передачи, иначе передаем делитель
            if (divisor == tmp)
            {
                input_sign = {4,4,1,1,1,1};
                input_sign = resolve(input_sign,(int) round(sqrt(tmp)));
                (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: N: " << input_sign.N << endl : cout << "";
                divisor = 1;
            } else 
            {
                tmp /= divisor;
                cout << "[TRANSMIT_SIGN]: Transmiting SIGN PART from A to B." << endl;
                step_1 = fastpow(divisor, input_sign.D, input_sign.N);
                int step_2 = fastpow(step_1, input_sign.C, input_sign.N);
                sign_res *= step_2;
            }
        }
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: message: " << message << endl : cout << "";
        (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign: " << sign << endl : cout << "";
        (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: divisor: " << divisor << endl : cout << "";
        (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: tmp: " << tmp << endl : cout << "";
        (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: step_1: " << step_1 << endl : cout << "";
        (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign_res: " << sign_res << endl : cout << "";
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    }
    if (sign_res == sign)
    {
        cout << "[TRANSMIT_SIGN]: Sign transmit successfull." << endl;
    } else 
    {
        cout << "[TRANSMIT_SIGN]: Sign transmit failled." << endl;
    }
}
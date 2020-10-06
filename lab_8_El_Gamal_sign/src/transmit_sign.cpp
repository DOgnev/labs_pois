#include "../inc/transmit_sign.h"

bool DEBUG_TRANSMIT_SIGN = true;

int search_divisor(int number)
{
    for (int i = 2; i < ceil(sqrt(number)); i++)
    {
        if ((number % i) == 0)
        {
            return i;
        }
    }
    return number;
}

void transmit_sign(string message)
{   
    data input_sign = {4,4,1,1,1,1};
    input_sign = resolve(input_sign, 50);
    int key = 13; // Масштаб подписи
    int S1 = 1, S2 = 1, sign = 1, sign_res = 1, step_1 = 1;
    cout << "[TRANSMIT_SIGN]: Transmiting SIGN." << endl;
    sign = get_sign(message, key); // Получаем подпись по переданному сообщению.
    int tmp = sign, divisor = 1;
    while (!(tmp == 0))
    {
        divisor = 1;
        if (tmp < input_sign.divisor_p)
        {
            cout << "[TRANSMIT_SIGN]: Transmiting LAST SIGN PART from A to B." << endl;
            //Заворачиваем подпись и передаем
            S1 = fastpow(input_sign.G, input_sign.K, input_sign.divisor_p);
            S2 = ((tmp - input_sign.X * S1) * input_sign.K_inv) % (input_sign.divisor_p - 1);
            (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: S1: " << S1 << endl : cout << "";
            S2 = S2 < 0 ? S2 + input_sign.divisor_p - 1 : S2;
            (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: S2: " << S2 << endl : cout << "";
            cout << "[TRANSMIT_SIGN]: Resolving SIGN." << endl;
            sign_res = (fastpow(input_sign.Y, S1, input_sign.divisor_p) * fastpow(S1, S2, input_sign.divisor_p)) % input_sign.divisor_p;
            step_1 = fastpow(input_sign.G,tmp,input_sign.divisor_p);
            if (sign_res == step_1)
            {
                cout << "[TRANSMIT_SIGN]: SIGN transmit success" << endl;
            } else 
            {
                cout << "[TRANSMIT_SIGN]: SIGN transmit failed" << endl;
                //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
                (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: message: " << message << endl : cout << "";
                (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign: " << sign << endl : cout << "";
                (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: divisor: " << divisor << endl : cout << "";
                (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: tmp: " << tmp << endl : cout << "";
                (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: step_1: " << step_1 << endl : cout << "";
                (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign_res: " << sign_res << endl : cout << "";
                (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign_res: " << S1 << endl : cout << "";
                (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign_res: " << S2 << endl : cout << "";
                (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign_res: " << input_sign.divisor_p << endl : cout << "";
                //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
            }
            tmp /= input_sign.divisor_p;
            //Ищем делитель для передачи
        } else if (tmp >= input_sign.divisor_p)
        {
            //Если вдруг делитель целый, то пересчитываем коэффициенты передачи, иначе передаем делитель
            divisor = search_divisor(tmp);
            if (divisor == tmp)
            {
                input_sign = {4,4,1,1,1,1};
                input_sign = resolve(input_sign, tmp * 2);
                divisor = 1;
            } else 
            {
                tmp /= divisor;
                cout << "[TRANSMIT_SIGN]: transmiting SIGN PART from A to B." << endl;
                S1 = fastpow(input_sign.G, input_sign.K, input_sign.divisor_p);
                S2 = ((divisor - input_sign.X * S1) * input_sign.K_inv) % (input_sign.divisor_p - 1);
                S2 = S2 < 0 ? S2 + input_sign.divisor_p - 1 : S2;
                cout << "[TRANSMIT_SIGN]: Resolving SIGN." << endl;
                sign_res = (fastpow(input_sign.Y,S1,input_sign.divisor_p) * fastpow(S1,S2,input_sign.divisor_p)) % input_sign.divisor_p;
                step_1 = fastpow(input_sign.G,divisor,input_sign.divisor_p);
                if (sign_res == step_1)
                {
                    cout << "[TRANSMIT_SIGN]: SIGN transmit success" << endl;
                } else 
                {
                    cout << "[TRANSMIT_SIGN]: SIGN transmit failed" << endl;
                    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
                    (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: message: " << message << endl : cout << "";
                    (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign: " << sign << endl : cout << "";
                    (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: divisor: " << divisor << endl : cout << "";
                    (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: tmp: " << tmp << endl : cout << "";
                    (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: step_1: " << step_1 << endl : cout << "";
                    (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign_res: " << sign_res << endl : cout << "";
                    (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign_res: " << S1 << endl : cout << "";
                    (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign_res: " << S2 << endl : cout << "";
                    (DEBUG_TRANSMIT_SIGN == true) ? cout << "[DEBUG|TRANSMIT_SIGN]: sign_res: " << input_sign.divisor_p << endl : cout << "";
                    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
                }
            }
        }
    }
}
#include "../inc/bitsumm.h"

bool DEBUG_BITSUMM = false;

int bitsumm(int message, int key)
{
    int tmp = message > key ? message : key;
    int last_bit_message, last_bit_key, summ = 0, result = 0, counter = 0;

    //Считаем побитовую сумму двух чисел
    while(tmp != 0)
    {
        summ <<= 1;
        last_bit_message = message & 1;
        last_bit_key = key & 1;
        summ += (last_bit_message ^ last_bit_key);
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        (DEBUG_BITSUMM == true) ? cout << "[DEBUG|BITSUMM]: last_bit_message " << last_bit_message << endl : cout << "";
        (DEBUG_BITSUMM == true) ? cout << "[DEBUG|BITSUMM]: last_bit_key " << last_bit_key << endl : cout << "";
        (DEBUG_BITSUMM == true) ? cout << "[DEBUG|BITSUMM]: summ " << summ << endl : cout << "";
         //--------------------СЕКЦИЯ ДЕБАГА ----------------------------// 
        message >>= 1;
        key >>= 1;
        tmp >>= 1;
        counter ++;
    }
    // Переворачиваем битовую последовательность в ответе (ответ получается зеркальным)
    while(counter != 0)
    {
        result <<= 1;
        last_bit_message = summ & 1;
        result += last_bit_message;   
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        (DEBUG_BITSUMM == true) ? cout << "[DEBUG|BITSUMM]: last_bit_message " << last_bit_message << endl : cout << "";
        (DEBUG_BITSUMM == true) ? cout << "[DEBUG|BITSUMM]: result " << result << endl : cout << "";
        (DEBUG_BITSUMM == true) ? cout << "[DEBUG|BITSUMM]: summ " << summ << endl : cout << "";
         //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        summ >>= 1;
        counter --;
    }
    return result;
}
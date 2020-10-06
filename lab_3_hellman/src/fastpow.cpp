#include "../inc/fastpow.h"

bool DEBUG_FASTPOW = false; // Чекер для дебага

//Определяем значение выражения base^index mod divisor.
int fastpow(int base, int index, int divisor)
{
    int last_bit;
    int curent_result = 1;
    int curent_multiplier = base;
   while(index != 0)
    {
        last_bit = index & 1; // Забираем последний бит
        if (last_bit == 1) //Получаем остаток от деления текущего разряда двоичного числа
        {
            curent_result *= curent_multiplier;
            curent_result %= divisor;
        }
        curent_multiplier *= curent_multiplier; 
        curent_multiplier %= divisor;
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        (DEBUG_FASTPOW == true) ? cout << "[DEBUG|FASTPOW]: last_bit= " << last_bit << endl : cout << "";
        (DEBUG_FASTPOW == true) ? cout << "[DEBUG|FASTPOW]: curent_multiplier= " << curent_multiplier << endl : cout << "";
        (DEBUG_FASTPOW == true) ? cout << "[DEBUG|FASTPOW]: curent_result= " << curent_result << endl : cout << "";
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        index >>= 1; // Битовый сдвиг на 1 разряд вправо
    }
    return curent_result;
}
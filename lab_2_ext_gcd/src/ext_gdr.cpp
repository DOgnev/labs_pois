#include "../inc/ext_gdr.h"

bool DEBUG_EXT = false; // Чекер дебага
 
ext_nod_exit ext_gcd(int divisor, int number) // Функция вычисляет значение НОД чисел divisor и number, а также находит их инверсии.
{
    if(divisor < number) return {0,0,0}; //Если divisor < number, тогда выходим с занулением ответа;
    ext_nod_data U = {divisor, 1, 0}, V = {number, 0, 1};
    while (V.gcd != 0)
    {
        int integer_part = U.gcd / V.gcd;
        ext_nod_data T = {U.gcd % V.gcd, U.divisor - integer_part * V.divisor, U.number - integer_part * V.number};
        U = V;
        V = T;
    }
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    (DEBUG_EXT == true) ? cout << "[DEBUG|EXT_GDR]: U= " << U.gcd <<":"<< U.divisor <<":"<< U.number << endl : cout << "";
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    return {U.gcd, U.divisor, U.number};
}
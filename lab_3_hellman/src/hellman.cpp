#include "../inc/hellman.h"

using namespace std;

//Функция проверки что число простое
bool simple_check(int number)
{
    if ((number % 2) == 0) return false; // Если число четное, то 
    for (int counter = 3; counter < round(sqrt(number)); counter += 2) 
    {
        if (number % counter == 0)
        {
            return false;
        }
    }
    return true;
};

//Определение исходных данных
data resolve(data input)
{
    srand(time(NULL));
    int divisor_q;
    divisor_q = (100 + rand() % 400);
    input.divisor = 2 * divisor_q + 1;
    while (!simple_check(input.divisor))
    {
        while (!simple_check(divisor_q))
        {
            divisor_q = (100 + rand() % 400);
        }
        input.divisor = 2 * divisor_q + 1;
    }
    input.base = (100 + rand() % input.divisor - 1);
    while (!(fastpow(input.base, divisor_q, input.divisor) != 1) && (input.base < input.divisor - 1) && (input.base > 0))
    {
        input.base = (100 + rand() % input.divisor - 1);
    }
    input.Xa = (100 + rand() % input.divisor)* 2;
    input.Xb = (100 + rand() % input.divisor)* 2;

    while(input.Xa == input.Xb)
    {
        input.Xb = (100 + rand() % input.divisor) * 2;
    }

    input.Ya = fastpow(input.base,input.Xa,input.divisor);
    input.Yb = fastpow(input.base,input.Xb,input.divisor);

    input.Za = fastpow(input.Yb,input.Xa,input.divisor);
    input.Zb = fastpow(input.Ya,input.Xb,input.divisor);

    return input;
}
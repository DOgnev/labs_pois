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

int random(int delta)
{
    int divisor_q;
    srand(time(0));
    divisor_q = delta / 10 + (rand() % delta);
    while(!simple_check(divisor_q))
    {
        divisor_q = delta / 10 + (rand() % delta);
    }
    return divisor_q;
}

//Определение исходных данных
data resolve(data input)
{
    //Ищем пару Q и P, такие, что P = 2 * Q + 1 и P,Q - простые
    int divisor_q;
    input.divisor = 4;
    while (!simple_check(input.divisor))
    {
        {
            divisor_q = random(500);
        }
        input.divisor = 2 * divisor_q + 1;
    }
    //Генерируем G, пока оно не будет удовлетворять условиям 1 < G < P - 1, pow(G,Q) mod P != 1
    input.base = random(input.divisor - 1);
    while (!(fastpow(input.base, divisor_q, input.divisor) != 1) && (input.base < input.divisor - 1) && (input.base > 0))
    {
        input.base = random(input.divisor - 1);
    }
    //Генерируем Xa и Xb, такие, что Xa != Xb
    input.Xa = random(input.divisor) * 2;
    input.Xb = random(input.divisor) * 2;

    while(input.Xa == input.Xb)
    {
        input.Xb = random(input.divisor) * 2;
    }
    //Вычисляем Ya,Yb такое, что Y = pow(G,X) mod P
    input.Ya = fastpow(input.base,input.Xa,input.divisor);
    input.Yb = fastpow(input.base,input.Xb,input.divisor);
    //Вычисляем Za,Zb такое, что Z = pow(Y,X) mod P
    input.Za = fastpow(input.Yb,input.Xa,input.divisor);
    input.Zb = fastpow(input.Ya,input.Xb,input.divisor);

    return input;
}
#include "../inc/resolve.h"

using namespace std;

bool DEBUG_RESOLVE = false;

//Функция проверки число на простоту
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
    int divisor_Q;
    srand(time(0));
    divisor_Q = delta / 10 + (rand() % delta);
    while(!simple_check(divisor_Q))
    {
        divisor_Q = delta / 10 + (rand() % delta);
    }
    return divisor_Q;
}

//Определение исходных данных
data resolve(data input)
{
    int divisor_Q;
    input.divisor = 4;
    //Ищем пару Q и P, такие, что P = 2 * Q + 1 и P,Q - простые
    while (!simple_check(input.divisor))
    {
        {
            divisor_Q = random(200);
        }
        input.divisor = 2 * divisor_Q + 1;
    }
    //Генерируем G, пока оно не будет удовлетворять условиям 1 < G < P - 1, pow(G,Q) mod P != 1
    input.base = random(input.divisor - 1);
    while (!(fastpow(input.base, divisor_Q, input.divisor) != 1) && (input.base < input.divisor - 1) && (input.base > 0))
    {
        input.base = random(input.divisor - 1);
    }
    //Генерируем X, пока оно не будет удовлетворять условию X < P - 1
    input.X = (100 + rand() % input.divisor - 1);
    while (!(input.X < input.divisor - 1))
    {
        input.X = random(input.divisor - 1);
    }
    //Вычисляем Y такое, что Y = pow(G,X) mod P
    input.Y = fastpow(input.base, input.X, input.divisor);
    //Генерируем K, пока оно не будет удовлетворять условию K < P - 1
    input.K = random(input.divisor - 1);
    while (!(input.K < input.divisor))
    {
        input.K = random(input.divisor - 1);
    }
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: P: " << input.divisor << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: G: " << input.base << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: X: " << input.X << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: Y: " << input.Y << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: K: " << input.K << endl : cout << "";
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    return input;
}
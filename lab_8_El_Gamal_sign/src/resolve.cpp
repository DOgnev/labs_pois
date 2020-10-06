#include "../inc/resolve.h"

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
    mt19937 gen(time(0));
    uniform_int_distribution<> dist(delta/2,delta); // Определяем диапазон значений
    int divisor_q = 4;
    // Крутим генератор, пока не находим простое Q
    while(!simple_check(divisor_q))
    {
        divisor_q = dist(gen);
    }
    return divisor_q;
}

//Определение исходных данных
data resolve(data input, int delta)
{
    while (!(input.K_inv > 1))
    {
        input = {4,4,1,1,1,1,1};
        ext_nod_exit invertion;
        input.divisor_p = 4;
        //Ищем пару Q и P, такие, что P = 2 * Q + 1 и P,Q - простые
        while (!simple_check(input.divisor_p))
        {
            {
                input.divisor_q = random(delta);
            }
            input.divisor_p = 2 * input.divisor_q + 1;
        }
        //Расчитываем G, такое, что pow(G,Q) mod P != 1 и 0 < G < P - 1
        input.G = random(input.divisor_p - 1);
        while (!(fastpow(input.G, input.divisor_q, input.divisor_p) != 1) && (input.G < input.divisor_p - 1) && (input.G > 0))
        {
            input.G = random(input.divisor_p - 1);
        }
        input.X = random(input.divisor_p);
        while (!(input.X < input.divisor_p))
        {
            input.X = random(input.divisor_p);
        }
        //Расчитываем Y, такое, что Y = pow(G,X) mod P
        input.Y = fastpow(input.G, input.X, input.divisor_p);
        //Ищем K, такое, что gcd(K,P - 1) = 1 и 0 < K < P - 1
        input.K = random(input.divisor_p - 1);
        while (!( (invertion.gcd == 1) && (input.K < input.divisor_p - 1) && (input.K > 0)))
        {
            input.K = random(input.divisor_p - 1);
            invertion = ext_gcd(input.divisor_p - 1, input.K);
        }
        //Ищем K_inv, такое, что K_inv * K mod P = 1
        input.K_inv = invertion.number_invertion < 0 ? (invertion.number_invertion + input.divisor_p - 1) : invertion.number_invertion;
    }
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: P: " << input.divisor_p << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: Q: " << input.divisor_q << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: G: " << input.G << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: X: " << input.X << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: Y: " << input.Y << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: K: " << input.K << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: K_inv: " << input.K_inv << endl : cout << "";
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    return input;
}
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
    while (!(input.D > 1))
    {
        input = {4,4,1,1,1,1};
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
        //Определяем N 
        input.N = input.divisor_p * input.divisor_q;
        //Определяем phi
        input.phi = ((input.divisor_p - 1) * (input.divisor_q - 1));
        //Ищем C, такое, что gcd(C,phi) = 1 и 0 < C < phi
        while (!( (invertion.gcd == 1) && (input.C < input.phi) && (input.C > 0)))
        {
            input.C = random(input.phi);
            invertion = ext_gcd(input.phi, input.C);
        }
        //Ищем D, такое, что C * D mod phi = 1
        input.D = invertion.number_invertion < 0 ? (invertion.number_invertion + input.phi) : invertion.number_invertion;
    }
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: P: " << input.divisor_p << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: Q: " << input.divisor_q << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: N: " << input.N << endl : cout << endl;
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: Phi: " << input.phi << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: C: " << input.C << endl : cout << "";
    (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: D: " << input.D << endl : cout << "";
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    return input;
}
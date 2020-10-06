#include "../inc/resolve.h"

bool DEBUG_RESOLVE = true;
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
    //Ищем пару Da и Db, такие, что D > 1 - простые
    while (!((input.Da > 1) && (input.Db > 1)))
    {
        //Ищем пару Q и P, такие, что P = 2 * Q + 1 и P,Q - простые
        int divisor_q;
        ext_nod_exit invertion_a, invertion_b;
        input.divisor = 4;
        while (!simple_check(input.divisor))
        {
            {
                divisor_q = random(500);
            }
            input.divisor = 2 * divisor_q + 1;
        }
        input.Ca = 0;
        input.Cb = 0;
        //Ищем пару Ca и Cb, такие, что gcd (C,P) = 1 и 1 < C < P - 1 - простые
        while (!((input.Ca != input.Cb) && (invertion_a.gcd == 1) && (invertion_b.gcd == 1) && (input.Ca < input.divisor - 1) && (input.Cb < input.divisor - 1) && (input.Ca > 0) && (input.Cb > 0)))
        {
            input.Ca = random(input.divisor - 1);
            input.Cb = random(input.divisor - 1);
            invertion_a = ext_gcd(input.divisor - 1, input.Ca);
            invertion_b = ext_gcd(input.divisor - 1, input.Cb);
        }
            //Определяем инверсию С, как D (C * D mod (P - 1) = 1)
            input.Da = invertion_a.number_invertion < 0 ? (invertion_a.number_invertion + (input.divisor - 1)) : invertion_a.number_invertion;
            input.Db = invertion_b.number_invertion < 0 ? (invertion_b.number_invertion + (input.divisor - 1)) : invertion_b.number_invertion;
        }
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
        (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: P: " << input.divisor << endl : cout << endl;
        (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: Ca: " << input.Ca << endl : cout << endl;
        (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: Cb: " << input.Cb << endl : cout << endl;
        (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: Da: " << input.Da << endl : cout << endl;
        (DEBUG_RESOLVE == true) ? cout << "[DEBUG|RESOLVE]: Db: " << input.Db << endl : cout << endl;
        //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    return input;
}
#include "../inc/generator.h"

bool DEBUG_GENERATOR = true;

//Определяем последовательность по заданному семени
string generator(int seed)
{
    string result = "";
    generator_key key = {1,1,4,1};
    cout << "[GENERATOR]: Generating params. Enter sequence length" << endl;
    cin >> key.number;
    key.number = key.number < 5 ? key.number = 5 : key.number;
    cout << "[GENERATOR]: Parsing" << endl;
    //Генерируем A, B, C параметры
    while(!simple_check(key.C))
    {
        key.C = random(500);
    }
    while (!((gcd(key.C, key.B) == 1) && (key.B != 1) && (key.B < key.C - 1)))
    {
        key.B = random(500);
    }
    while (!((key.A < key.C) && (key.A != 1)))
    {
        key.A = random(50);
    }
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    (DEBUG_GENERATOR == true) ? cout << "[DEBUG|GENERATOR]: A: " << key.A << endl : cout << "";
    (DEBUG_GENERATOR == true) ? cout << "[DEBUG|GENERATOR]: B: " << key.B << endl : cout << "";
    (DEBUG_GENERATOR == true) ? cout << "[DEBUG|GENERATOR]: C: " << key.C << endl : cout << "";
    (DEBUG_GENERATOR == true) ? cout << "[DEBUG|GENERATOR]: seed: " << seed << endl : cout << "";
    (DEBUG_GENERATOR == true) ? cout << "[DEBUG|GENERATOR]: number: " << key.number << endl : cout << "";
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    int tmp = (key.A * seed + key.B) % key.C;
    for (int i = 0; i < key.number; i++)
    {
        tmp = (key.A * tmp + key.B) % key.C;
        result += to_string(tmp) + " ";
    }
    result += "!";
    return result;
}
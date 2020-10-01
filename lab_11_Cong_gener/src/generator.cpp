#include "../inc/generator.h"

bool DEBUG_GENERATOR = true;

//Определяем последовательность по заданному семени
string generator(int seed)
{
    string RESULT = "";
    generator_key KEY = {1,1,4,1};
    cout << "generating params. Enter sequence length" << endl;
    cin >> KEY.number;
    KEY.number = KEY.number < 5 ? KEY.number = 5 : KEY.number;
    cout << "Parsing" << endl;
    while(!simplecheck(KEY.C))
    {
        KEY.C = random(500);
    }
    while (!((gcd(KEY.C, KEY.B) == 1) && (KEY.B != 1) && (KEY.B < KEY.C - 1)))
    {
        KEY.B = random(500);
    }
    while (!((KEY.A < KEY.C) && (KEY.A != 1)))
    {
        KEY.A = random(50);
    }
    if (DEBUG_GENERATOR == true)
    {
        cout << "KEY.A = " << KEY.A << endl;
        cout << "KEY.B = " << KEY.B << endl;
        cout << "KEY.C = " << KEY.C << endl;
        cout << "seed = " << seed << endl;
        cout << "KEY.NUMBER = " << KEY.number << endl;
    }
    int tmp = (KEY.A * seed + KEY.B) % KEY.C;
    for (int i = 0; i < KEY.number; i++)
    {
        tmp = (KEY.A * tmp + KEY.B) % KEY.C;
        RESULT += to_string(tmp) + " ";
    }
    RESULT += "!";
    return RESULT;
}
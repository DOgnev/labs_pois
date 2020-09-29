#include "../inc/fastpow.h"

bool DEBUG_FASTPOW = false;

//Определяем значение остатка для заданного числа
int fastpow(int argument_a, int argument_x, int argument_p)
{
    int last_bit;
    int y = 1;
    int s = argument_a;
   while(argument_x != 0)
    {
        last_bit = argument_x&1;
        if (last_bit == 1) 
        {
            y = (y*s) % argument_p;
        }
        s = (s*s) % argument_p;
        if (DEBUG_FASTPOW == true)
        {
            cout << "[DEBUG_FASTPOW fastpow]: lb= " << last_bit << endl;
            cout << "[DEBUG_FASTPOW fastpow]: y= " << y << endl;
            cout << "[DEBUG_FASTPOW fastpow]: s= " << s << endl;
        }
        argument_x = argument_x >> 1;
    }
    return y;
}
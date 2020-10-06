#ifndef HACKING_H
#define HACKING_H

#include <sstream>

#include "generator.h"

using namespace std;

struct hacked_key
{
    int A;
    int B;
    int C;
};
//Пробрасываем строку в целое число
int str_to_int(string string);
//Забираем строку от генератора заданной длины
string take_seq(string sequence);
//Взламываем полученную последовательность
hacked_key hacking(string stolen_sequence);

#endif
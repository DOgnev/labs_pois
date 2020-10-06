#ifndef RESOLVE_H
#define RESOLVE_H

#include <cstdlib>
#include <ctime>
#include "fastpow.h"
#include "ext_gcd.h"

using namespace std;
//Структура данных
struct data
{
    int divisor;
    int Ca;
    int Cb;
    int Da;
    int Db;
};

//Функция проверки число на простоту
bool simple_check(int number);
//Функция рандомного числа
int random(int delta);
//Определение исходных данных
data resolve(data input);

#endif
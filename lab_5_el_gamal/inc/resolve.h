#ifndef RESOLVE_H
#define RESOLVE_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "fastpow.h"

using namespace std;
//Структура данных
struct data
{
    int divisor;
    int base;
    int X;
    int Y;
    int K;
};

//Функция проверки число на простоту
bool simple_check(int number);

//Генерация случайного числа
int random(int delta);

//Определение исходных данных
data resolve(data input);

#endif
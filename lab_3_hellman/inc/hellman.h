#ifndef HELLMAN_H
#define HELLMAN_H

#include <iostream>
#include <ctime>
#include "fastpow.h"

using namespace std;
//Структура данных
struct data
{
    int divisor;
    int base;
    int Ya;
    int Yb;
    int Xa;
    int Xb;
    int Za;
    int Zb;
};

//Функция проверки число на простоту
bool simple_check(int number);

//Определение исходных данных
data resolve(data input);

#endif
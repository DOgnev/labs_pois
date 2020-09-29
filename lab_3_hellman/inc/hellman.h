#ifndef HELLMAN_H
#define HELLMAN_H

#include <iostream>
#include <ctime>
#include "fastpow.h"

using namespace std;
//Структура данных
struct data
{
    int argument_p;
    int argument_g;
    int Ya;
    int Yb;
    int Xa;
    int Xb;
    int Za;
    int Zb;
};

//Функция проверки число на простоту
bool simplecheck(int argument_p);

//Определение исходных данных
data resolving(data Input);

#endif
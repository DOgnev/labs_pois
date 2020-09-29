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
    int argument_p;
    int argument_g;
    int X;
    int Y;
    int K;
};

//Функция проверки число на простоту
bool simplecheck(int argument_p);

//Функция рандомного числа
int random (int delta);

//Определение исходных данных
data resolving(data Input);

#endif
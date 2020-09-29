#ifndef RESOLVE_H
#define RESOLVE_H

#include <cstdlib>
#include <ctime>
#include <random>
#include "fastpow.h"
#include "ext_gdr.h"

using namespace std;
//Структура данных
struct data
{
    int argument_p;
    int argument_q;
    int G;
    int X;
    int Y;
    int K;
    int K_inv;
};

//Функция проверки число на простоту
bool simplecheck(int argument_p);
//Функция рандомного числа
int random (int delta);
//Определение исходных данных
data resolving(data Input, int delta);

#endif
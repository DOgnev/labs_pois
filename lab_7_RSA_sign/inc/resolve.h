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
    int divisor_p;
    int divisor_q;
    int N;
    int phi;
    int C;
    int D;
};

//Функция проверки число на простоту
bool simple_check(int number);

//Функция рандомного числа
int random (int delta);

//Определение исходных данных
data resolve(data input, int delta);

#endif
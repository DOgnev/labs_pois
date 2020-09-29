#ifndef RESOLVE_H
#define RESOLVE_H

#include <cstdlib>
#include <ctime>
#include "fastpow.h"
#include "ext_gdr.h"

using namespace std;
//Структура данных
struct data
{
    int argument_p;
    int Ca;
    int Cb;
    int Da;
    int Db;
};

//Функция проверки число на простоту
bool simplecheck(int argument_p);
//Функция рандомного числа
int random (int delta);
//Определение исходных данных
data resolving(data Input);

#endif
#ifndef RESOLVE_H
#define RESOLVE_H

#include <cstdlib>
#include <ctime>
#include <random>
#include <math.h>

using namespace std;
//Структура данных

//Функция проверки число на простоту
bool simplecheck(int argument_p);
//Функция рандомного числа
int random (int delta);
//Функция нахождения НОД
int gcd(int a, int b);

#endif
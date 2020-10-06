#ifndef CREATE_SEQ_H
#define CREATE_SEQ_H

#include <random>
#include <iostream>
#include <cstring>
#include <ctime>
#include <array>

using namespace std;

//Функция генерации случайного числа
int random(int min, int max);

//Функция генерации последовательности
string sequence_creator(int length);

//Функция проверки длины строки, если строка более 40 символов, тогда генерируем новую несколько раз.
string prevalidation (int length);
#endif
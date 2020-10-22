//Модуль вспомогательных функций. 
#ifndef RESOLVE_H
#define RESOLVE_H

#include <cstdlib>
#include <ctime>
#include <random>
#include <windows.h>
#include "extGcd.h"

using namespace std;

//Функция проверки число на простоту
bool isSimple(int number);

//Функция генерации случайного числа
int computeRandom(int delta);

//Функция генерации случайного простого числа 3 до delta - 1
int computeSimpleRandom(int delta);

//Функция генерации случайного простого числа от 0 до delta - 1
int computeRandomFromZero(int delta);

//Функция перемешивания элементов массива
void computeRandomArray(int inputArray[], int arrayLength);

//Функция отображения массива
void showArray(int inputArray[], int arrayLength);

//Функция смены местами переменных
void swapDigits(int *a, int *b);

void dragonRun(int number, bool succsess);
#endif
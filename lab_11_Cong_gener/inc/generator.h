#ifndef GENERATOR_H
#define GENERATOR_H

#include <math.h>
#include <iostream>
#include <cstring>

#include "resolve.h"

using namespace std;

struct generator_key
{
    int A;
    int B;
    int C;
    int number;
};
//Задает строку с заданным зерном
string generator(int seed);

#endif
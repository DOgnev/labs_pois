#ifndef EXT_GCD_H
#define EXT_GCD_H

#include<iostream>

using namespace std;

struct ext_nod_data
{
    int gcd;
    int divisor;
    int number;
};

struct ext_nod_exit
{
    int gcd;
    int divisorInvertion;
    int numberInvertion;
};

//Вычисляется значение инверсии исходя из обобщенного алгоритма Евклида;
ext_nod_exit extendGcd(int divisor, int number);

#endif
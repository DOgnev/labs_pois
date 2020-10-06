#ifndef EXT_GDR_H
#define EXT_GDR_H

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
    int divisor_invertion;
    int number_invertion;
};

//Вычисляется значение инверсии исходя из обобщенного алгоритма Евклида;
ext_nod_exit ext_gcd(int divisor, int number);

#endif
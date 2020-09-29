#ifndef EXT_GDR_H
#define EXT_GDR_H

#include<iostream>

using namespace std;

//Вычисляется значение инверсии исходя из обобщенного алгоритма Евклида;
struct ext
{
    int a1;
    int a2;
    int a3;
};
struct ext_nod_exit
{
    int NOD;
    int x;
    int y;
};
 
ext_nod_exit ext_nod(int a, int b);

#endif
#ifndef EXT_NOD_CPP
#define EXT_NOD_CPP

#include "include.cpp"

//Чекер для дебага
bool DEBUG_NOD = false;

//НОД двух чисел, код взят из википедии;
int NOD(int argument_m, int argument_c)
{
    int a,b;
    if (argument_m > argument_c){
        a = argument_m;
        b = argument_c;
    } else {
        a = argument_c;
        b = argument_m;
    }
    if (DEBUG_NOD == true)
    {
        cout << "[DEBUG NOD]: a= " << a << endl;
        cout << "[DEBUG NOD]: b= " << b << endl;
    }
	a = abs(a);
	b = abs(b);
	while (b) {
		while (a >= b)
			a -= b;
		if (!a)
			return b;
		do {
			b -= a;
		} while (b >= a);
    }
    return a;
}

//Вычисляется значение инверсии исходя из обобщенного алгоритма Евклида;
struct ext_nod_exit
{
    int nod;
    int y;
    int x;
};
 
ext_nod_exit ext_nod(int a, int b)
{
    ext_nod_exit U = {a, 1, 0}, V = {b, 0, 1};
    while (V.nod != 0)
    {
        int q = U.nod / V.nod;
        ext_nod_exit T = {U.nod % V.nod, U.y - q * V.y, U.x - q * V.x};
        U = V;
        V = T;
    }
    if (DEBUG_NOD == true)
    {
        cout << "[DEBUG NOD]: U= " << U.x << U.y << U.nod << endl;
    }
    if (U.x < 0)
    {
        U.x += a;
    }
    return U;
}
#endif
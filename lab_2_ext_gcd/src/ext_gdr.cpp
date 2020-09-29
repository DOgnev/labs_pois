#include "../inc/ext_gdr.h"

using namespace std;
//Чекер для дебага
bool DEBUG_EXT = false;
 
ext_nod_exit ext_nod(int a, int b)
{
    ext_nod_exit U = {a, 1, 0}, V = {b, 0, 1};
    while (V.a1 != 0)
    {
        int q = U.a1 / V.a1;
        ext_nod_exit T = {U.a1 % V.a1, U.a2 - q * V.a2, U.a3 - q * V.a3};
        U = V;
        V = T;
    }
    if (DEBUG_EXT == true)
    {
        cout << "[DEBUG NOD]: U= " << U.a1 << U.a2 << U.a3 << endl;
    }
    return U;
}
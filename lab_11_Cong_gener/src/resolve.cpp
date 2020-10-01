#include "../inc/resolve.h"

//Функция проверки число на простоту
bool simplecheck(int argument_p)
{
    int quotient;
    for (int i = 2; i < argument_p; i++) 
    {
        if (argument_p % i == 0)
        {
            return false;
        }
    }
    return true;
};

int random (int delta)
{
    int Q;
    mt19937 gen(time(0));
    uniform_int_distribution<> dist(4,delta);
    Q = dist(gen);
    return Q;
}

int gcd(int a, int b) {
   int c,t = a;
   a = a < b ? a : b;
   b = a < b ? b : t;
   t = 0;
   while (b) {
      c = a % b;
      a = b;
      b = c;        
   }
   return abs(a);
 }
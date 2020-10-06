#include "../inc/resolve.h"

bool simple_check(int number)
{
    if ((number % 2) == 0) return false; // Если число четное, то 
    for (int counter = 3; counter < round(sqrt(number)); counter += 2) 
    {
        if (number % counter == 0)
        {
            return false;
        }
    }
    return true;
};

int random(int delta)
{
    mt19937 gen(time(0));
    uniform_int_distribution<> dist(delta/2,delta); // Определяем диапазон значений
    int random_number = 4;
    // Крутим генератор, пока не находим простое Q
    while(!simple_check(random_number))
    {
        random_number = dist(gen);
    }
    return random_number;
}
//Алгорит евклида для нахождения НОД
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
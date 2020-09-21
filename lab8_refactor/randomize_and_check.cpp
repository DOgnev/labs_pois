#ifndef RANDOMIZE_AND_CHECK_CPP
#define RANDOMIZE_AND_CHECK_CPP

#include "include.cpp"

//Функция проверки число на простоту
bool simplecheck(int argument_p)
{
    for (int i = 2; i < argument_p; i++) 
    {
        if (argument_p % i == 0)
        {
            return false;
        }
    }
    return true;
};

//Функция присвоения простого числа
int random_simple(int delta)
{   
    if(delta == 0)
    {
        delta = 100;
    }
    srand(time(0));
    int randomizer = (delta + rand() % delta);
    while(!simplecheck(randomizer)) 
    {
        if (randomizer < (delta + delta))
        {
            randomizer++;
        } else {
            randomizer = (delta + rand() % delta);
        }
    }
    return randomizer;
};

//поиск делителя
int search_divisor(int Input)
{
    for (int i = 2; i <= Input; i++)
    {
        if (Input % i == 0)
        {
            return i;     
        }
    }
    return 0;
}

#endif
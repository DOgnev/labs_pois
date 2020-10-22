#include "../inc/get_sign.h"

bool DEBUG_SIGN = false;

//Поиск значения обратного хэша.
int get_sign(string message, int poly)
{
    char input[message.length()]; 
    strcpy(input, message.c_str());
    int length = strlen(input);
    int hash[length];
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    (DEBUG_SIGN == true) ? cout << "[DEBUG|SIGN]: length: " << length  << endl : cout << "";
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    hash[0] = input[0];
    for(int counter = 1; counter < strlen(input); counter++) 
    {
        hash[counter] = hash[counter - 1] * poly + input[counter];
    }
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    (DEBUG_SIGN == true) ? cout << "[DEBUG|SIGN]: hash: " << hash[length - 1]  << endl : cout << "";
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    return hash[length-1] % (int) pow(2,30);         
}
#ifndef CREATE_SIGN_CPP
#define CREATE_SIGN_CPP

#include "include.cpp"

//Чекер для дебага
bool DEBUG_SIGN = false;

//Расчет подписи

unsigned int Sign(int Inp, int poly)
{
    string In = to_string(Inp);
    char Input[In.length()]; 
    strcpy(Input, In.c_str());
    int length = strlen(Input);
    unsigned int hash[length];
    if (DEBUG_SIGN == true)
    {
        cout << "[DEBUG_SIGN Sign]: length= " << length << endl; 
    }
    hash[0] = Input[0];
    for(int i = 1; i < strlen(Input); i++) 
    {
        hash[i] = hash[i-1] * poly + Input[i];
    }
    if (DEBUG_SIGN == true)
    {
        cout << "[DEBUG_SIGN Sign]: hash= " << hash[length-1] << endl; 
    }
    return hash[length-1];         
}
#endif
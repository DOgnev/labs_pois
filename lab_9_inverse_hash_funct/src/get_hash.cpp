#include "../inc/get_hash.h"

bool DEBUG_SIGN = false;

int get_hash(string Message, int poly)
{
    string In = Message;
    char Input[In.length()]; 
    strcpy(Input, In.c_str());
    int length = strlen(Input);
    int hash[length];
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
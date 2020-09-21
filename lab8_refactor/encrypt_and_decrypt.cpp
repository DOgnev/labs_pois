#ifndef ENCRYPT_AND_DECRYPT_CPP
#define ENCRYPT_AND_DECRYPT_CPP

#include "include.cpp"
using namespace std;

//Возвращение значения ASCII 
int encrypt(char Input)
{
    return (int) Input;
}

//Возвращение символа по ASCII 
char decrypt(int Input)
{
    return (char) Input;
}

/*int main ()
{
    char Input;
    cin >> Input;
    encrypt(Input);
    decrypt(encrypt(Input));
    return 0;
}*/
#endif
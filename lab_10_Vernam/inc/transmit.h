#ifndef TRANSMIT_H
#define TRANSMIT_H

#include "create_seq.h"
#include "bitsumm.h"

using namespace std;

struct transmiting_data
{
    string message;
    string key;
    string encrypt;
};
//Функция шифрования данных
transmiting_data solve_encrypt(transmiting_data input);

//Функция расшифрования данных
string solve_message(transmiting_data input);

#endif
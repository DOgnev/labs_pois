#ifndef TRANSMIT_H
#define TRANSMIT_H

#include "create_seq.h"
#include "bitsumm.h"

using namespace std;

struct transmiting_data
{
    string MESSAGE;
    string KEY;
    string ENCRYPT;
};
transmiting_data solve_encrypt(transmiting_data INPUT);
string solve_message(transmiting_data INPUT);

#endif
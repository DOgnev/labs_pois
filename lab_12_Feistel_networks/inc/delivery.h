#ifndef DELIVERY_H
#define DELIVERY_H

#include <string>
#include <sstream>
#include <cstring>
#include "generate_key.h"

using namespace std;

struct encrypt_data
{
    string left_block_encrypted;
    string right_block_encrypted;
    int block_length;
};

int solve_left(int curent_left, int curent_right);

encrypt_data encryptor(string block);

string decryptor(encrypt_data encrypt);

#endif
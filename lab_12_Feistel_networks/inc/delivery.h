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
//Парсер строки в число
int str_to_int(string string);
//Решение левого блока
int solve_left(int curent_left, int curent_right);
//Функция шифрования
encrypt_data encryptor(string block);
//Парсер дешифрования
string decryptor(encrypt_data encrypt);

#endif
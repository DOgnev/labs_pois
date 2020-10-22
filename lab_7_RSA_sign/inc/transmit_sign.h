#ifndef TRANSMIT_SIGN_H
#define TRANSMIT_SIGN_H

#include "fastpow.h"
#include "resolve.h"
#include "get_sign.h"
#include <string>

using namespace std;

//Функция поиска делителя
int search_divisor(int number);

//Функция передачи подписи
void transmit_sign(string message);
#endif
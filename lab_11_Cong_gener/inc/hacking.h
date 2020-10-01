#ifndef HACKING_H
#define HACKING_H

#include <sstream>

#include "generator.h"

using namespace std;

struct hacked_key
{
    int A;
    int B;
    int C;
};

int str_to_int(string str);
string take_U_seq(string Sequence);
hacked_key hacking(string U);

#endif
#include "../inc/bitsumm.h"

bool DEBUG_BITSUMM = false;

//Определяем значение остатка для заданного числа
int bitsumm(int Message, int Key)
{
    int t = Message > Key ? Message : Key;
    int last_bit_Message, last_bit_Key, Summ = 0, Result = 0, Q = 0;
    while(t != 0)
    {
        Summ <<= 1;
        last_bit_Message = Message & 1;
        last_bit_Key = Key & 1;
        Summ += (last_bit_Message ^ last_bit_Key);   
        if (DEBUG_BITSUMM == true)
        {
            cout << "[DEBUG_BITSUMM]: last_bit_m= " << last_bit_Message << endl;
            cout << "[DEBUG_BITSUMM]: last_bit_k= " << last_bit_Key << endl;
            cout << "[DEBUG_BITSUMM]: Summ= " << Summ << endl;
        }
        Message >>= 1;
        Key >>= 1;
        t >>= 1;
        Q ++;
    }
    while(Q != 0)
    {
        Result <<= 1;
        last_bit_Message = Summ & 1;
        Result += last_bit_Message;   
        if (DEBUG_BITSUMM == true)
        {
            cout << "[DEBUG_BITSUMM]: last_bit_message= " << last_bit_Message << endl;
            cout << "[DEBUG_BITSUMM]: Result= " << Result << endl;
            cout << "[DEBUG_BITSUMM]: Summ= " << Summ << endl;
        }
        Summ >>= 1;
        Q --;
    }
    return Result;
}
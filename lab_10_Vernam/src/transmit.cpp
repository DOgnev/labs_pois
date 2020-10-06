#include "../inc/transmit.h"

transmiting_data solve_encrypt(transmiting_data input)
{
    input.encrypt = "";
    for (int counter = 0; counter < input.message.length(); counter++)
    {
        input.encrypt += (char) bitsumm((int) input.message[counter],(int) input.key[counter]);
    }
    return input;
}

string solve_message(transmiting_data input)
{
    string message_res = "";
    for (int counter = 0; counter < input.encrypt.length(); counter++)
    {
        message_res += (char) bitsumm((int) input.encrypt[counter], (int) input.key[counter]);
    }
    return message_res;
}

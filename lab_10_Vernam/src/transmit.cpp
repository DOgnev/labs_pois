#include "../inc/transmit.h"

transmiting_data solve_encrypt(transmiting_data Input)
{
    Input.ENCRYPT = "";
    for (int i = 0; i < Input.MESSAGE.length(); i++)
    {
        Input.ENCRYPT += (char) bitsumm((int) Input.MESSAGE[i],(int) Input.KEY[i]);
    }
    return Input;
}

string solve_message(transmiting_data Input)
{
    string MESSAGE_RES = "";
    for (int i = 0; i < Input.ENCRYPT.length(); i++)
    {
        MESSAGE_RES += (char) bitsumm((int) Input.ENCRYPT[i], (int) Input.KEY[i]);
    }
    return MESSAGE_RES;
}

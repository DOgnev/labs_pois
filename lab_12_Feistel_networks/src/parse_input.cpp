#include "../inc/parse_input.h"
bool DEBUG_PARSE = false;

string parse_input_block(string input)
{
//Секция переменных
    string tmp = "";
    string resolve = "";
    const int block_length = 8;
    if (!(input.length() % block_length == 0))
    {
        for (int counter = 0; counter < (input.length() % block_length); counter++)
        {
            input += "$";
        }
    }
    input += "!";
    (DEBUG_PARSE == true) ? (cout << "[DEBUG|parse_input_block]: input: " << input << endl) : cout << "";
    int block_id = 0;
    int sym_id = 0;
    string block_data = "";
    while (!((input[sym_id] == '!') && (sym_id % block_length == 0)))
    {
        for (int block_sym_id = 0; block_sym_id < block_length; block_sym_id++)
        {
            block_data += input[block_sym_id + (block_id * block_length)];
            sym_id++;
        }
    (DEBUG_PARSE == true) ? (cout << "[DEBUG|parse_input_block]: sym_id: " << sym_id << endl) : cout << "";
    (DEBUG_PARSE == true) ? (cout << "[DEBUG|parse_input_block]: block_data: " << block_data << endl) : cout << "";
    string decrypted_block = decryptor(encryptor(block_data));
    (DEBUG_PARSE == true) ? (cout << "[DEBUG|parse_input_block]: decrypted_block: " << decrypted_block << endl) : cout << "";
    tmp += decrypted_block;
    (DEBUG_PARSE == true) ? (cout << "[DEBUG|parse_input_block]: tmp: " << tmp << endl) : cout << "";
    block_data = "";
    block_id++;
    (DEBUG_PARSE == true) ? (cout << "[DEBUG|parse_input_block]: control_symbol: " << input[sym_id] << endl) : cout << "";
    }
    int counter = 0;
    while (tmp[counter] != '$')
    {
        resolve += tmp[counter];
        (DEBUG_PARSE == true) ? (cout << "[DEBUG|parse_input_block]: tmp[counter]: " << tmp[counter] << endl) : cout << "";
        counter++;
    }
    (DEBUG_PARSE == true) ? (cout << "[DEBUG|parse_input_block]: resolve: " << resolve << endl) : cout << "";
    return resolve;
}
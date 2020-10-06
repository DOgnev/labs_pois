#include "../inc/delivery.h"
#include "../inc/bitsumm.h"

bool DEBUG_DELIVERY = false;
int round_range = 5;

int str_to_int(string string)
{
    stringstream stream_string;
    int integer_value;
    if (string.empty())
    {
        return 0;
    }
    stream_string << string;
    stream_string >> integer_value;
    return integer_value;
}

int solve_left(int curent_left, int curent_right)
{
    (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|solve_left: curents_left]: " << curent_left << endl) : cout << "";
    (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|solve_right: curent_right]: " << curent_right << endl) : cout << "";
    return bitsumm(curent_right, curent_left);
}

encrypt_data encryptor(string block)
{
    int qurent_round = 1;
    string left_block_part = "", right_block_part = "";
    int left_block_part_array[block.length()/2], right_block_part_array[block.length()/2];
    for (int block_sym_id = 0; block_sym_id < block.length(); block_sym_id++)
    {
        if (block_sym_id < block.length() / 2) left_block_part += block[block_sym_id];
        else right_block_part += block[block_sym_id];
    }
    (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|encryptor: left_block_part]: " << left_block_part << endl) : cout << "";
    (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|encryptor: right_block_part]: " << right_block_part << endl) : cout << "";
    
    for (int counter = 0; counter < block.length()/2; counter++)
    {
        left_block_part_array[counter] = (int) left_block_part[counter];
        right_block_part_array[counter] = (int) right_block_part[counter];
        (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|encryptor: left_block_part_array]: " << to_string(left_block_part_array[counter]) << endl) : cout << "";
        (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|encryptor: right_block_part_array]: " << to_string(right_block_part_array[counter]) << endl) : cout << "";
    }
    for (qurent_round; qurent_round <= round_range; qurent_round++)
    {
        int left_block_round[block.length() / 2];
        for (int counter = 0; counter < block.length() / 2; counter++)
        {
        left_block_round[counter] = solve_left(left_block_part_array[counter], generate_key(qurent_round, (int) right_block_part_array[counter]));
        (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|encryptor: left_block_round]: " << to_string(left_block_round[counter]) << endl) : cout << "";
        left_block_part_array[counter] = right_block_part_array[counter];
        right_block_part_array[counter] = left_block_round[counter];
        (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|encryptor: left_block_part_array]: " << to_string(left_block_part_array[counter]) << endl) : cout << "";
        (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|encryptor: right_block_part_array]: " << to_string(right_block_part_array[counter]) << endl) : cout << "";
        }
    }
    encrypt_data result;
    result.block_length = block.length() / 2;
    for (int counter = 0; counter < block.length() / 2; counter++)
    {
        result.left_block_encrypted += round_range % 2 == 0 ? to_string(left_block_part_array[counter]) + " " : to_string(right_block_part_array[counter]) + " ";
    }
    result.left_block_encrypted += "!";
    (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|encryptor: result]: " << result.left_block_encrypted << endl) : cout << "";
    for (int counter = 0; counter < block.length() / 2; counter++)
    {
        result.right_block_encrypted += round_range % 2 == 0 ? to_string(right_block_part_array[counter]) + " " : to_string(left_block_part_array[counter]) + " ";
    }
    result.right_block_encrypted += "!";
    (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|encryptor: result]: " << result.right_block_encrypted << endl) : cout << "";
    return result;
}

string decryptor(encrypt_data encrypt)
{
    int qurent_round_inv = round_range;
    int left_encrypt_part_array[encrypt.block_length] , right_encrypt_part_array[encrypt.block_length];
    string left_encrypt_part = "", right_encrypt_part = "";
    string number = "";
    int counter = 0, array_counter = 0;
    while(encrypt.left_block_encrypted[counter] != '!')
    {
        while(encrypt.left_block_encrypted[counter] != ' ')
        {
            number += encrypt.left_block_encrypted[counter];
            counter++;
        }
        left_encrypt_part_array[array_counter] = str_to_int(number);
        (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|decryptor: left_encrypt_part_array]: " << to_string(left_encrypt_part_array[array_counter]) << endl) : cout << "";
        number = "";
        counter++;
        array_counter++;
    }
    counter = 0, array_counter = 0;
    while(encrypt.right_block_encrypted[counter] != '!')
    {
        while(encrypt.right_block_encrypted[counter] != ' ')
        {
            number += encrypt.right_block_encrypted[counter];
            counter++;
        }
        right_encrypt_part_array[array_counter] = str_to_int(number);
        (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|decryptor: right_encrypt_part_array]: " << to_string(right_encrypt_part_array[array_counter]) << endl) : cout << "";
        number = "";
        counter++;
        array_counter++;
    }
    for (qurent_round_inv; qurent_round_inv >= 1; qurent_round_inv--)
    {
        int left_encrypt_round[encrypt.block_length];
        for (int counter = 0; counter < encrypt.block_length; counter++)
        {
            left_encrypt_round[counter] = solve_left(left_encrypt_part_array[counter], generate_key(qurent_round_inv, right_encrypt_part_array[counter]));
            (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|decryptor: left_encrypt_round]:"  << to_string(left_encrypt_round[counter]) << endl) : cout << "";
            left_encrypt_part_array[counter] = right_encrypt_part_array[counter];
            right_encrypt_part_array[counter] = left_encrypt_round[counter];
            (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|decryptor: left_encrypt_part_array]: " << to_string(left_encrypt_part_array[counter]) << endl) : cout << "";
            (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|decryptor: right_encrypt_part_array]: " << to_string(right_encrypt_part_array[counter]) << endl) : cout << "";
        }
    }
    string result;
    for (int counter = 0; counter < encrypt.block_length; counter++)
    {
        result += round_range % 2 == 0 ? (char) left_encrypt_part_array[counter] : (char) right_encrypt_part_array[counter];
        (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|decryptor: result]: " << result << endl) : cout << "";
    }
    for (int counter = 0; counter < encrypt.block_length; counter++)
    {
        result += round_range % 2 == 0 ? (char) right_encrypt_part_array[counter] : (char) left_encrypt_part_array[counter];
        (DEBUG_DELIVERY == true) ? (cout << "[DEBUG|decryptor: result]:" << result << endl) : cout << "";
    }
    return result;
}
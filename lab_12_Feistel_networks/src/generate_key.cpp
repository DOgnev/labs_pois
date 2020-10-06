#include "../inc/generate_key.h"

bool DEBUG_GEN_KEY = false;

int generate_key(int round, int right_part)
{
    int function_scale = 256;
    int result = (right_part + round) % function_scale;
    (DEBUG_GEN_KEY == true) ? (cout << "[DEBUG|generate_key: round] " << round << endl) : cout << "";
    (DEBUG_GEN_KEY == true) ? (cout << "[DEBUG|generate_key: right_part] " << right_part << endl) : cout << "";
    (DEBUG_GEN_KEY == true) ? (cout << "[DEBUG|generate_key: result] " << result << endl) : cout << "";
    return result; 
}
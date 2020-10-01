#include "../inc/get_hash.h"
#include <ctype.h>
int main()
{
    int KEY = 13, Output;
    string Message;
    cout << "Enter message" << endl;
    cin >> Message;
    Output = get_hash(Message, KEY);
    cout << "Hash Success: " << Output <<endl;
    system("pause");
    return 0;
}
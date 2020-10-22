#include "../inc/get_sign.h"
#include <ctype.h>
int main()
{
    int key = 21; // Масштабирующий коэффициент
    int output;
    string message;
    cout << "[MAIN]: Enter message." << endl;
    cin >> message;
    output = get_sign(message, key);
    cout << "[MAIN]: Hash Success: " << output <<endl;
    system("pause");
    return 0;
}
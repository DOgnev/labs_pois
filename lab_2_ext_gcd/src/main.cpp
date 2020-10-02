#include "../inc/ext_gdr.h"

int main()
{
    ext_nod_exit RESULT;
    int number, divisor;
    cout << "[MAIN]: Searching invertion to c (d): number * number_a_invertion mod divisor = 1, !!! number must be less than divisor !!!" << endl;
    cout << "[MAIN]: Enter number " << endl;
    cin >> number;
    cout << "[MAIN]: Enter divisor " << endl;
    cin >> divisor;
    if (number > 0 && divisor > 0) ext_gcd(number, divisor);
    else cout << "[ERROR]: number or divisor must be more than 0" << endl;
    RESULT.gcd == 0 ? cout << "[ERROR]: divisor must be less than number" << endl : cout << "[MAIN]: number_invertion= "<< RESULT.number_invertion << endl;
    system("pause");
    return 0;
}
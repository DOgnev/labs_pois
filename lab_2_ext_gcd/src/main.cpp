#include "../inc/ext_gcd.h"

int main()
{
    ext_nod_exit result;
    int number, divisor;
    cout << "[MAIN]: Searching invertion to c (d): number * number_a_invertion mod divisor = 1, HINT: number must be less than divisor." << endl;
    cout << "[MAIN]: Enter number." << endl;
    cin >> number;
    cout << "[MAIN]: Enter divisor." << endl;
    cin >> divisor;
    if (number > 0 && divisor > 0) result = ext_gcd(divisor, number);
    else cout << "[ERROR]: number or divisor must be more than 0." << endl;
    if (result.gcd != 1)
    {
        cout << "[ERROR]: divisor and number aren't simple with each other or divisor less than number, invertion doesn't exist" << endl;
        system("pause");
        return 0;
    }
    result.number_invertion = result.number_invertion < 0 ? result.number_invertion += divisor : result.number_invertion;
    cout << "[MAIN]: number invertion: " << result.number_invertion << endl;
    system("pause");
    return 0;
}
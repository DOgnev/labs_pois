#include "../inc/hacking.h"

int main()
{
    hacked_key result;
    result = hacking(take_seq(generator(11)));
    cout << "[MAIN]: Result: A " << result.A << endl;
    cout << "[MAIN]: Result: B " << result.B << endl;
    cout << "[MAIN]: Result: C " << result.C << endl;
    system("pause");
    return 0;
}
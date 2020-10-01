#include "../inc/hacking.h"

int main()
{
    string Sequence;
    hacked_key RESULT;
    RESULT = hacking(take_U_seq(generator(11)));
    cout << "Result: A " << RESULT.A << endl;
    cout << "Result: B " << RESULT.B << endl;
    cout << "Result: C " << RESULT.C << endl;
    system("pause");
    return 0;
}
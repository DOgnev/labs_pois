#include "../inc/fastpow.h"

bool DEBUG_FASTPOW_MAIN = false;

int main()
{
    int a, x, p, result;
    cout << "Solve: pow(a,x) mod p " << endl;
    cout << "Expect a " << endl;
    // Получаем основание   
    cin >> a; 
    cout << "Expect x " << endl;
    // Получаем показатель
    cin >> x;
    cout << "Expect p " <<endl;
    // Получаем делитель
    cin >> p;
    // Вычисляем
    result = fastpow(a ,x ,p);
    if (DEBUG_FASTPOW_MAIN == true)
    {
        cout << "[DEBUG_FASTPOW main]: a= " << a << endl;
        cout << "[DEBUG_FASTPOW main]: x= " << x << endl;
        cout << "[DEBUG_FASTPOW main]: p= " << p << endl;
        cout << "[DEBUG_FASTPOW main]: Result= " << result << endl;
    }
    cout << " Result: " << result << endl;  
    system("pause");
    return 0;
}
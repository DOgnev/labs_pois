#include<stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;
//Чекер для дебага
bool DEBUG = false;
//Вычисление логарифма двоичного
int log2(int b){
    
    if (DEBUG == true)
    {
        int z = floor(log(b) / log(2));
        cout << "[DEBUG log2]: b= " << b << endl;
        cout << "[DEBUG log2]: z= " << z << endl;
        return z;
    } else {
        return floor(log(b) / log(2));
    }
}

int fastpow(int argument_a, int argument_x, int argument_p)
{
    int last_bit;
    int t;
    int y = 1;
    int s = argument_a;
//Определяем границу
    t = log2(argument_x);
    if (DEBUG == true)
    {
        cout << "[DEBUG fastpow]: t= " << t << endl;
    }
//Определяем значение остатка для заданного числа
    for(int i = 0; i <= t; i++)
    {
        last_bit = argument_x&1;
        if (last_bit == 1) 
        {
            y = (y*s) % argument_p;
        }
        s = (s*s) % argument_p;
        if (DEBUG == true)
        {
            cout << "[DEBUG fastpow]: lb= " << last_bit << endl;
            cout << "[DEBUG fastpow]: y= " << y << endl;
            cout << "[DEBUG fastpow]: s= " << s << endl;
        }
        argument_x = argument_x >> 1;
    }
    return y;
}

int main()
{
    int a,x,p,result;

    cout << "Solve: pow(a,x) mod p " << endl;
    cout << "Expect a " << endl;
    cin >> a;
    cout << "Expect x " << endl;
    cin>>x;
    cout << "Expect p " <<endl;
    cin>>p;
    result = fastpow(a,x,p);
    if (DEBUG == true)
    {
        cout << "[DEBUG main]: a= " << a << endl;
        cout << "[DEBUG main]: x= " << x << endl;
        cout << "[DEBUG main]: p= " << p << endl;
        cout << "[DEBUG main]: Result= " << result << endl;
    }
    cout << " Result: " << result << endl;  
    system("pause");
    return 0;
}
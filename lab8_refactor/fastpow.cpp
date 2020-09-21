#ifndef FASTPOW_CPP
#define FASTPOW_CPP

#include "include.cpp"

//Чекер для дебага
bool DEBUG_THIS = false;
//Вычисление логарифма двоичного
int log2(int b){
    
    if (DEBUG_THIS == true)
    {
        int z = floor(log(b) / log(2));
        cout << "[DEBUG_THIS log2]: b= " << b << endl;
        cout << "[DEBUG_THIS log2]: z= " << z << endl;
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
    if (DEBUG_THIS == true)
    {
        cout << "[DEBUG_THIS fastpow]: t= " << t << endl;
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
        if (DEBUG_THIS == true)
        {
            cout << "[DEBUG_THIS fastpow]: lb= " << last_bit << endl;
            cout << "[DEBUG_THIS fastpow]: y= " << y << endl;
            cout << "[DEBUG_THIS fastpow]: s= " << s << endl;
        }
        argument_x = argument_x >> 1;
    }
    return y;
}

#endif
/*int main()
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
    if (DEBUG_THIS == true)
    {
        cout << "[DEBUG_THIS main]: a= " << a << endl;
        cout << "[DEBUG_THIS main]: x= " << x << endl;
        cout << "[DEBUG_THIS main]: p= " << p << endl;
        cout << "[DEBUG_THIS main]: Result= " << result << endl;
    }
    cout << " Result: " << result << endl;  
    system("pause");
    return 0;
}*/
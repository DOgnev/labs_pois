#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<ctime>

using namespace std;
//Чекер для дебага
bool DEBUG = false;
//Структура данных
struct data
{
    int argument_p;
    int argument_g;
    int Ya;
    int Yb;
    int Xa;
    int Xb;
    int Za;
    int Zb;
};

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
//Функция проверки число на простоту
bool simplecheck(int argument_p)
{
    int quotient;
    for (int i = 2; i < argument_p; i++) 
    {
        if (argument_p % i == 0 && argument_p == i)
        {
            return false;
        }
    }
    return true;
};
//Функция первичной проверки данных на валидность входных данных
bool validation(data Input)
{    
    if (Input.argument_g <= 1 || Input.argument_g >= (Input.argument_p-1))
    {
        cout << "[VALIDATION]: Wrong g argument, it must be bigger than 1 and smaller than argument p - 1" << endl;
        return false;
    } else if (!simplecheck(Input.argument_p) || Input.argument_p < 3)
    {
        cout << "[VALIDATION]: Wrong p argument, it must be simple number or bigger than 2" << endl;
        return false;
    }
    return true;
}

int main()
{
    data Input;
    srand(time(0)); //Функция динамической рандомизации
    //Ожидание входных данных
    cout << "Waiting for data input" << endl;
    cout << "Enter argument p" << endl;
    cin >> Input.argument_p;
    cout << "Enter argument g" << endl;
    cin >> Input.argument_g;
    //Получаем значения от 1000 до 9990
    Input.Xa = (100 + rand() % 899)* 10;
    Input.Xb = (100 + rand() % 899)* 10;
    if (DEBUG == true)
    {
        cout << "[DEBUG main: Xa= " << Input.Xa << endl;
        cout << "[DEBUG main]: Xb= " << Input.Xb << endl;
    }
    //При совпадении ключей выполняем переопределение ключа.
    while(Input.Xa == Input.Xb)
    {
        cout << "[VALIDATION]: key Xa == Xb, rerandomize" << endl;
        Input.Xb = (100 + rand() % 899) * 10;
        if (DEBUG == true)
        {
            cout << "[DEBUG validator]: Xb= " << Input.Xb << endl;
        }
    }
    //Выполняем валидацию по входу
    if(!validation(Input))
    {
        cout << "Unexpected error" << endl;
        system("pause");
        return 1;
    }
    //Вычисляем данные и проверяем их достоверность
    cout << "Resolving public key" << endl;
    Input.Ya = fastpow(Input.argument_g,Input.Xa,Input.argument_p);
    Input.Yb = fastpow(Input.argument_g,Input.Xb,Input.argument_p);
    cout << "Key data solved:" << endl;
    cout << "A public key:" << Input.Ya <<endl;
    cout << "B public key:" << Input.Yb <<endl;
    cout << "A private key:" << Input.Xa << endl;
    cout << "B private key:" << Input.Xb << endl;
    cout << "Check it" << endl;
    Input.Za = fastpow(Input.Yb,Input.Xa,Input.argument_p);
    Input.Zb = fastpow(Input.Ya,Input.Xb,Input.argument_p);
    if (DEBUG == true)
    {
        cout << "[DEBUG main]: Za= " << Input.Za << endl;
        cout << "[DEBUG main]: Zb= " << Input.Zb << endl;
    }
    if (!(Input.Za == Input.Zb))
    {
        cout << "Unexpected error, Invalid Zab" << endl;
        system("pause");
        return 1;
    }
    cout << "Checksumm is valid. Zab=" << Input.Za << endl;
    system("pause");
    return 0;
}
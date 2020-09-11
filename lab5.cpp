#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<ctime>

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

//Функция проверки число на простоту
bool simplecheck(int argument_p)
{
    for (int i = 2; i < argument_p; i++) 
    {
        if (argument_p % i == 0)
        {
            return false;
        }
    }
    return true;
};

//Функция присвоения простого числа
int random_simple(int delta)
{   
    if(delta == 0)
    {
        delta = 100;
    }
    srand(time(0));
    int randomizer = (delta + rand() % delta);
    while(!simplecheck(randomizer)) 
    {
        if (randomizer < (delta + delta))
        {
            randomizer++;
        } else {
            randomizer = (delta + rand() % delta);
        }
    }
    return randomizer;
};

//Определяем структуру для входных данных
struct data
{
    int X = 1;
    int Y = 1;
    int K = 1;
    int argument_g = 1;
    int argument_p = random_simple(0);
};

struct transmit_data
{
    int A;
    int B;
};

data resolving(data Input, int delta)
{
    bool checker = false;
    Input.argument_p = random_simple(delta); 
    Input.argument_g = (2 + rand() % Input.argument_p-1);
    if (DEBUG == true)
    {
        cout << "[DEBUG res]: g= " << Input.argument_g << endl;
        cout << "[DEBUG res]: p= " <<  Input.argument_p  << endl;
    }
    while(!((Input.argument_g < Input.argument_p-1) && (Input.argument_g > 1)&&(checker == false)))
    {
        Input.argument_g = (2 + rand() % Input.argument_p-1);
        int a,b,c;
        a = fastpow(Input.argument_g,Input.argument_p-1,Input.argument_p);
        b = fastpow(Input.argument_g,Input.argument_p-1/2,Input.argument_p);
        c = fastpow(Input.argument_g,Input.argument_p-1/3,Input.argument_p);
        if (a == b == c)
        {
            checker = true;
        } else {
            checker = false;
        }
    }
    Input.X = (2 + rand() % Input.argument_p);
    while(!((Input.X < Input.argument_p) && (Input.X > 1)))
    {
        Input.X = (2 + rand() % Input.argument_p);
    }
    Input.Y = fastpow(Input.argument_g,Input.X,Input.argument_p);
    Input.K = (2 + rand() % Input.argument_p-1);
    while(!((Input.K < Input.argument_p-1) && (Input.K > 1)))
    {
        Input.K = (2 + rand() % Input.argument_p-1);
    }
    if (DEBUG == true)
    {
        cout << "[DEBUG res]: g= " << Input.argument_g << endl;
        cout << "[DEBUG res]: p= " <<  Input.argument_p  << endl;
        cout << "[DEBUG res]: K= " <<  Input.K  << endl; 
        cout << "[DEBUG res]: X= " <<  Input.X  << endl; 
        cout << "[DEBUG res]: Y= " <<  Input.Y  << endl; 
    }
    return Input;
}

int search_divisor(int Input)
{
    for (int i = 2; i < Input; i++)
    {
        if (Input % i == 0)
        {
            return i;     
        }
    }
    return 0;
}

int transmit(int m, data Input)
{
    transmit_data Message;
    int m_res;
    Message.A = fastpow(Input.argument_g, Input.K, Input.argument_p);
    Message.B = (fastpow(Input.Y,Input.K,Input.argument_p) * (m % Input.argument_p)) % Input.argument_p;
    cout << "Transmiting Data from A to B" << endl;
    m_res = ((Message.B % Input.argument_p) * fastpow(Message.A,Input.argument_p-1-Input.X,Input.argument_p)) % Input.argument_p;
    if(m == m_res)
    {
        cout << "Transmiting Success" << endl;
        return m_res;
    } else {
        cout << "Transmiting Failed" << endl;
    }
}

int main()
{
    data Input;
    int divisor = 1;
    int res_message = 1, transmit_message = 1;
    //Определение входных данных
    Input = resolving(Input, 0);
    cout << "Enter message" << endl;
    cin >> transmit_message; 
    int tmp = transmit_message;
    while(tmp != 0)
    {
        if (tmp < Input.argument_p)
        {
            res_message *= transmit(tmp,Input);
            tmp /= Input.argument_p;
            if (DEBUG == true)
            {
                cout << "[DEBUG main LAST ITTER]: res_message= " << res_message << endl;
            }
        } else if (tmp > Input.argument_p) 
        {
            divisor = search_divisor(tmp);
            if (divisor != 0)
            {
                tmp /= divisor;
                res_message *= transmit(divisor,Input);
            } else {
                Input = resolving(Input, tmp);
            } 
            if (DEBUG == true)
            {
                cout << "[DEBUG main]: res_message= " << res_message << endl;
                cout << "[DEBUG main]: tmp= " << tmp << endl;
                cout << "[DEBUG main]: divisor= " << divisor << endl; 
            }
        }
    }
    if (res_message == transmit_message)
    {
        cout << "Success transmition: " << res_message << endl;
    } else {
        cout << "Unexpected message: " << res_message << endl;
    }
    system("pause");
    return 0;
}
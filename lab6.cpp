#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<ctime>

using namespace std;
//Чекер для дебага
bool DEBUG = true;
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

//НОД двух чисел, код взят из википедии
int NOD(int argument_m, int argument_c)
{
    int a,b;
    if (argument_m > argument_c){
        a = argument_m;
        b = argument_c;
    } else {
        a = argument_c;
        b = argument_m;
    }
    if (DEBUG == true)
    {
        cout << "[DEBUG NOD]: a= " << a << endl;
        cout << "[DEBUG NOD]: b= " << b << endl;
    }
	a = abs(a);
	b = abs(b);
	while (b) {
		while (a >= b)
			a -= b;
		if (!a)
			return b;
		do {
			b -= a;
		} while (b >= a);
    }
    return a;
}
//Вычисляется значение инверсии исходя из соотношения cd mod m = 1;
int inverse(int argument_c, int argument_m)
{
    for (int i = 2; i < argument_c*argument_m; i++)
    {
        if ((i * argument_c % argument_m) == 1)
        {
            return i;
        }
    }
}

//Определяем структуру для входных данных
struct data
{
    int argument_q = random_simple(0);
    int argument_p = random_simple(0);
    int phi = 0;
    int N = 0;
    int d = 0;
    int c = 0;
};

data resolving(data Input, int delta)
{
    while(!(Input.d < Input.phi))
    {
    bool checker = false;
        Input.argument_p = random_simple(delta);
        Input.argument_q = random_simple(delta);
    while(Input.argument_p == Input.argument_q)
    {
        Input.argument_p = random_simple(delta);
        Input.argument_q = random_simple(delta);
    }
    Input.N = Input.argument_p * Input.argument_q;
    Input.phi =  (Input.argument_p-1) * (Input.argument_q-1);
    if (DEBUG == true)
    {
        cout << "[DEBUG res]: q= " << Input.argument_q << endl;
        cout << "[DEBUG res]: p= " << Input.argument_p << endl;
    }
    Input.c = (2 + rand() % Input.phi);
    while(!((Input.c < Input.phi) && (Input.c > 1)))
    {
        Input.c = (2 + rand() % Input.phi);
    }
    Input.d = inverse(Input.c, Input.phi);
    }
    if (DEBUG == true)
    {
        cout << "[DEBUG res]: q= " << Input.argument_q << endl;
        cout << "[DEBUG res]: p= " <<  Input.argument_p  << endl;
        cout << "[DEBUG res]: c= " <<  Input.c  << endl; 
        cout << "[DEBUG res]: d= " <<  Input.d  << endl; 
        cout << "[DEBUG res]: N= " <<  Input.N  << endl; 
        cout << "[DEBUG res]: phi= " <<  Input.phi  << endl; 
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
    int m_res;
    int X1;
    X1 = fastpow(m, Input.c, Input.N);
    cout << "Transmiting Data from A to B" << endl;
    cout << "Resolving message" << endl;
    m_res = fastpow(X1, Input.d, Input.N);
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
        if (tmp < Input.N)
        {
            res_message *= transmit(tmp,Input);
            tmp /= Input.N;
            if (DEBUG == true)
            {
                cout << "[DEBUG main LAST ITTER]: res_message= " << res_message << endl;
            }
        } else if (tmp > Input.N) 
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
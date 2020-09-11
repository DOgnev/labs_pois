#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<ctime>
#include<string.h>

using namespace std;
//Чекер для дебага
bool DEBUG = false;
int KEY = 43;
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
    long y = 1;
    long s = argument_a;
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
    while(!((Input.d < Input.phi) && (Input.d > 1)))
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

unsigned int Sign(int Inp, int poly)
{
    string In = to_string(Inp);
    char Input[In.length()]; 
    strcpy(Input, In.c_str());
    int length = strlen(Input);
    unsigned int hash[length];
    if (DEBUG == true)
    {
        cout << "[DEBUG Sign]: length= " << length << endl; 
    }
    hash[0] = Input[0];
    for(int i = 1; i < strlen(Input); i++) 
    {
        hash[i] = hash[i-1] * poly + Input[i];
    }
    if (DEBUG == true)
    {
        cout << "[DEBUG Sign]: hash= " << hash[length-1] << endl; 
    }
    return hash[length-1];         
}

int transmit_sign(int m, data Input_sign)
{
    int m_res;
    int X1;
    X1 = fastpow(m, Input_sign.c, Input_sign.N);
    cout << "Transmiting Sign from A to B" << endl;
    cout << "Resolving Sign" << endl;
    m_res = fastpow(X1, Input_sign.d, Input_sign.N);
    if(m == m_res)
    {
        cout << "Sign Transmiting Success" << endl;
        return m_res;
    } else {
        cout << "Sign Transmiting Failed" << endl;
    }
    return 0;
}

int transmit(int m, data Input)
{
    data Input_sign = resolving(Input_sign,0);
    int X1,S1,m_res;
    int w = 1;
    int s = 1;
    int divisor = 1;
    X1 = fastpow(m, Input.c, Input.N);
    cout << "Transmiting Data from A to B" << endl;
    S1 = Sign(m, KEY);
    s = S1;
    cout << "Transmiting Sign from A to B" << endl;
    m_res = fastpow(X1, Input.d, Input.N);
    while(s != 0)
    {
        Input = resolving(Input_sign, 0);
        if (s < Input_sign.N)
        {  
            w *= transmit_sign(s, Input_sign);
            s /= Input_sign.N;
            if (DEBUG == true)
            {
                cout << "[DEBUG transmit SIGN]: w= " << w << endl;
            }
        } else if (s > Input_sign.N) 
        {
            divisor = search_divisor(s);
            if (divisor != 0)
            {
                s /= divisor;
                w *= transmit_sign(divisor,Input_sign);
            } else {
                Input_sign = resolving(Input_sign, s);
            } 
            if (DEBUG == true)
            {
                cout << "[DEBUG transmit SIGN]: w= " << w << endl;
                cout << "[DEBUG transmit SIGN]: s= " << s << endl;
                cout << "[DEBUG transmit SIGN]: divisor= " << divisor << endl;
            }
        }
    }
    cout << "Resolving message" << endl;
    if((m == m_res) && (S1 == w))
    {
        cout << "Transmiting Success" << endl;
    } else {
        cout << "Transmiting Failed" << endl;
    }
    if (DEBUG == true)
    {
        cout << "[DEBUG transmit]: S1= " << S1 << endl;
        cout << "[DEBUG transmit]: w= " << w << endl;
        cout << "[DEBUG transmit]: m= " << m << endl;
        cout << "[DEBUG transmit]: m_res= " << m_res << endl;
    }
    return m_res;
}

int sender (int tmp, data Input)
{
    Input = resolving(Input, 0);
    int divisor;
    int  out = 1;
    while(tmp != 0)
    {
        if (tmp < Input.N)
        {  
            out *= transmit(tmp,Input);
            tmp /= Input.N;
            if (DEBUG == true)
            {
                cout << "[DEBUG sender LAST ITTER]: out= " << out << endl;
            }
        } else if (tmp > Input.N) 
        {
            divisor = search_divisor(tmp);
            if (divisor != 0)
            {
                tmp /= divisor;
                out *= transmit(divisor,Input);
            } else {
                Input = resolving(Input, tmp);
            } 
            if (DEBUG == true)
            {
                cout << "[DEBUG sender]: out= " << out << endl;
                cout << "[DEBUG sender]: tmp= " << tmp << endl;
                cout << "[DEBUG sender]: divisor= " << divisor << endl;
            }
        }
    }
    return out;       
}

int main()
{
    data Input;
    int res_message = 1, transmit_message = 1;
    //Определение входных данных
    Input = resolving(Input, 0);
    cout << "Enter message" << endl;
    cin >> transmit_message;
    res_message = sender(transmit_message,Input);
    if (res_message == transmit_message)
    {
        cout << "Success transmition: " << res_message << endl;
    } else {
        cout << "Unexpected message: " << res_message << endl;
    }
    system("pause");
    return 0;
}
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<ctime>
#include<string.h>

using namespace std;
//Чекер для дебага
bool DEBUG = true;
int KEY = 52;
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
    for (int i = 2; i < argument_m; i++)
    {
        if (((i * argument_c) % argument_m) == 1)
        {
            return i;
        }
    }
}

//Определяем структуру для входных данных
struct data
{
    int X = 1;
    int Y = 1;
    int K = 1;
    int K_inv = 1;
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
    srand(time(0));
    bool checker = false;
    Input.argument_p = random_simple(delta); 
    Input.argument_g = (2 + rand() % (Input.argument_p-1));
    if (DEBUG == true)
    {
        cout << "[DEBUG res]: g= " << Input.argument_g << endl;
        cout << "[DEBUG res]: p= " <<  Input.argument_p  << endl;
    }
    while(!((Input.argument_g < Input.argument_p-1) && (Input.argument_g > 1)&&(checker == false)))
    {
        Input.argument_g = (2 + rand() % (Input.argument_p-1));
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
    Input.X = (2 + rand() % (Input.argument_p-1));
    while(!((Input.X < Input.argument_p) && (Input.X > 1)))
    {
        Input.X = (2 + rand() % (Input.argument_p-1));
    }
    Input.Y = fastpow(Input.argument_g,Input.X,Input.argument_p);
    Input.K = (2 + rand() % (Input.argument_p-1));
    while(!((Input.K < Input.argument_p-1) && (Input.K > 1) && NOD(Input.K,Input.argument_p-1) == 1))
    {
        Input.K = (2 + rand() % (Input.argument_p-1));
    }
    Input.K_inv = inverse(Input.K,Input.argument_p);
    if (DEBUG == true)
    {
        cout << "[DEBUG res]: g= " << Input.argument_g << endl;
        cout << "[DEBUG res]: p= " <<  Input.argument_p  << endl;
        cout << "[DEBUG res]: K= " <<  Input.K  << endl;
        cout << "[DEBUG res]: K_inv= " <<  Input.K_inv  << endl;  
        cout << "[DEBUG res]: X= " <<  Input.X  << endl; 
        cout << "[DEBUG res]: Y= " <<  Input.Y  << endl; 
    }
    return Input;
}

int transmit_sign(int h_B,int h_A, data Input_sign)
{
    transmit_data Sign;
    int h_res,h_exp;
    Sign.A = fastpow(Input_sign.argument_g, Input_sign.K, Input_sign.argument_p);
    Sign.B = ((h_B-Input_sign.X*Sign.A) * Input_sign.K_inv) % (Input_sign.argument_p-1);
    cout << "Transmiting Sign from A to B" << endl;
    h_res = (fastpow(Input_sign.Y, Sign.A, Input_sign.argument_p) * fastpow(Sign.A, Sign.B, Input_sign.argument_p))% Input_sign.argument_p;
    h_exp = fastpow(Input_sign.argument_g,h_A,Input_sign.argument_p);
    if(h_res == h_exp)
    {
        cout << "Sign Transmiting Success" << endl;
        return h_A;
    } else {
        cout << "Sign Transmiting Failed" << endl;
    }
}

int transmit(int m, data Input)
{
    transmit_data hash;
    transmit_data Message;
    data Input_sign = resolving(Input_sign,0);
    int w = 1, divisor_a = 1, divisor_b = 1;
    int sa = 1, sb = 1; 
    int m_res;
    Message.A = fastpow(Input.argument_g, Input.K, Input.argument_p);
    Message.B = (fastpow(Input.Y,Input.K,Input.argument_p) * (m % Input.argument_p)) % Input.argument_p;
    cout << "Transmiting Data from A to B" << endl;
    m_res = ((Message.B % Input.argument_p) * fastpow(Message.A,Input.argument_p-1-Input.X,Input.argument_p)) % Input.argument_p;
    hash.B = Sign(m,KEY);
    hash.A = Sign(m_res,KEY);
    sb = hash.B;
    sa = hash.A;
    if (DEBUG == true)
    {
        cout << "[DEBUG transmit SIGN]: hA= " << hash.A << endl;
        cout << "[DEBUG transmit SIGN]: hB= " << hash.B << endl;
    }
    while(sa != 0)
    {
        Input = resolving(Input_sign, 0);
        if (sa < Input_sign.argument_p)
        {  
            w *= transmit_sign(sb,sa, Input_sign);
            sb /= Input_sign.argument_p;
            sa /= Input_sign.argument_p;
            if (DEBUG == true)
            {
                cout << "[DEBUG transmit SIGN]: w= " << w << endl;
            }
        } else if (sa > Input_sign.argument_p) 
        {
            divisor_a = search_divisor(sa);
            divisor_b = search_divisor(sb);
            if ((divisor_a != 0) && (divisor_a == divisor_b))
            {
                sa /= divisor_a;
                sb /= divisor_b;
                w *= transmit_sign(divisor_b,divisor_a,Input_sign);
            } else {
                Input_sign = resolving(Input_sign, sa);
            } 
            if (DEBUG == true)
            {
                cout << "[DEBUG transmit SIGN]: w= " << w << endl;
                cout << "[DEBUG transmit SIGN]: sa= " << sa << endl;
                cout << "[DEBUG transmit SIGN]: sb= " << sb << endl;
                cout << "[DEBUG transmit SIGN]: divisor= " << divisor_a << endl;
                cout << "[DEBUG transmit SIGN]: divisor= " << divisor_b << endl;
            }
        }
    }
    if((m == m_res) && (w == hash.A))
    {
        cout << "Transmiting Success" << endl; 
    } else {
        cout << "Transmiting Failed" << endl;
    }
    return m_res;
}

int sender (int m, data Input)
{
    Input = resolving(Input, 0);
    int divisor =1;
    int  out = 1;
    int tmp = m;
    while(tmp != 0)
    {
        if (tmp < Input.argument_p)
        {
            out *= transmit(tmp,Input);
            tmp /= Input.argument_p;
            if (DEBUG == true)
            {
                cout << "[DEBUG sender LAST ITTER]: out= " << out << endl;
            }
        } else if (tmp > Input.argument_p) 
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
    int divisor = 1;
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
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<ctime>

using namespace std;
//Чекер для дебага
bool DEBUG = false;
//Определяем структуру для проверки данных
struct check
{
    bool check_Ca_p = false;
    bool check_Cb_p = false;
    bool check_Ca_nequal_Cb = false;
};
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
    int Ca = 0;
    int Cb = 0;
    int Da = 0;
    int Db = 0;
    int argument_m = 0;
    int argument_p = random_simple(0);
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

data resolving(data Input,int delta)
{
    cout << "Resolving data" << endl;
    while(true)
    {
        srand(time(0));
        check Input_check;
        Input.argument_p = random_simple(delta);
        Input.Ca = 100 + rand() % 399;
        Input.Cb = 100 + rand() % 399;
        while(!(Input_check.check_Ca_p) && !(Input_check.check_Cb_p) && !(Input_check.check_Ca_nequal_Cb))
        {
            if (Input_check.check_Ca_p == false)
            {
                if (NOD(Input.Ca,Input.argument_p-1) != 1)
                {
                    Input.Ca = 50 + rand() % 100;
                    Input_check.check_Ca_nequal_Cb = false;
                } else {
                    Input_check.check_Ca_p = true; 
                }
                     
            }
            if (Input_check.check_Cb_p == false)
            {
                if (NOD(Input.Cb,Input.argument_p-1) != 1)
                {
                    Input.Cb = 50 + rand() % 100;
                    Input_check.check_Ca_nequal_Cb = false;
                } else {
                    Input_check.check_Cb_p = true;  
                }
                      
            }
            if (Input.Ca == Input.Cb)
            {
                Input.Ca = 50 + rand() % 100;
                Input_check.check_Ca_p = false;
                Input_check.check_Ca_nequal_Cb = false;
            } else {
                Input_check.check_Ca_nequal_Cb = true;
            }
        }
        Input.Da = inverse(Input.Ca,(Input.argument_p-1));
        Input.Db = inverse(Input.Cb,(Input.argument_p-1));
        if (!((Input.Da == Input.Db) || (Input.Da > Input.argument_p) || (Input.Db > Input.argument_p)))
        {
            break;
        }

    }
    if (DEBUG == true)
    {
        cout << "[DEBUG resolving]: Ca= " << Input.Ca << endl;
        cout << "[DEBUG resolving]: Cb= " << Input.Cb << endl;
        cout << "[DEBUG resolving]: Da= " << Input.Da << endl;
        cout << "[DEBUG resolving]: Db= " << Input.Db << endl;
        cout << "[DEBUG resolving]: p= " << Input.argument_p << endl;
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

int transmit(int message, data Input)
{
    int X1,X2,X3,X4;
    while(true)
    {
        X1 = fastpow(message,Input.Ca,Input.argument_p);
        X2 = fastpow(X1,Input.Cb,Input.argument_p);
        X3 = fastpow(X2,Input.Da,Input.argument_p);
        X4 = fastpow(X3,Input.Db,Input.argument_p);
        cout << "Transmitting A to B [itter 1]. X1: "<< X1 << endl;
        cout << "Transmitting B to A [itter 2]. X2: "<< X2 << endl;
        cout << "Transmitting A to B [itter 3]. X3: "<< X3 << endl;
        cout << "Solve message [itter 4]. X4: "<< X4 << endl;
        if (X4 == message)
        {
            cout << "Transmit Succesfull" << endl;
            break;
        } else {
            cout << "Transmit failed" << endl;
            Input = resolving(Input, message); 
        }
        if (DEBUG == true)
        {
            cout << "[DEBUG transmit]: Mess= " << message << endl;
            cout << "[DEBUG transmit]: X1= " << X1 << endl;
            cout << "[DEBUG transmit]: X2= " << X2 << endl;
            cout << "[DEBUG transmit]: X3= " << X3 << endl;
            cout << "[DEBUG transmit]: X4= " << X4 << endl;
        }
    }
    return X4;
}

int main()
{
    data Input;
    int divisor = 1;
    int res_message = 1;
    //Определение входных данных
    Input = resolving(Input, 0);
    cout << "Enter message" << endl;
    cin >> Input.argument_m; 
    int tmp = Input.argument_m;
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
    if (res_message == Input.argument_m)
    {
        cout << "Success transmition: " << res_message << endl;
    } else {
        cout << "Unexpected message: " << res_message << endl;
    }
    system("pause");
    return 0;
}
#include<stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;
//Чекер для дебага
bool DEBUG = false;
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
int inverse(int argument_m, int argument_c)
{
    int check = NOD(argument_m, argument_c);
    if (DEBUG == true)
    {
        cout << "[DEBUG inverse]: NOD= " << check << endl;
    }
    if (check == 1)
    {
        for (int i=1; i <= (argument_m-1); i++)
        {
            if (i * argument_c % argument_m == 1)
            {
                return i;
            }
        }
    } else {
        return 0;
    }
}

int main()
{
    int c,m,result;

    cout << "Solve d in: cd mod m = 1" << endl;
    cout << "Expect c " << endl;
    cin >> c;
    cout << "Expect m " << endl;
    cin >> m;
    result = inverse(m,c);
    if (DEBUG == true)
    {
        cout << "[DEBUG main]: c= " << c << endl;
        cout << "[DEBUG main]: m= " << m << endl;
        cout << "[DEBUG main]: d= " << result << endl;
    }
    if (result != 0)
    {
        cout << " Result d: " << result << endl;   
    } else {
        cout << " Unexpected result: " << result << endl; 
    }
 
    system("pause");
    return 0;
}
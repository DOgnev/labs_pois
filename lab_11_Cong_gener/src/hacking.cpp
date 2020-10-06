#include "../inc/hacking.h"

//Парсер строки в число
int str_to_int(string string)
{
    stringstream stream_string;
    int integer_value;
    if (string.empty())
    {
        return 0;
    }
    stream_string << string;
    stream_string >> integer_value;
    return integer_value;
}

//Определяем последовательность по заданному семени
string take_seq(string sequence)
{
    string number, U;
    int q = 0, T1, T2, T3, S1, S2, S3, S4, t, tmp;
    number = "";
        for (int i = 0; i < 4; i++)
        {
            while(sequence[q] != ' ')
            {
                number += sequence[q];
                q++;
            }
            S1 = i == 0 ? str_to_int(number): S1;
            S2 = i == 1 ? str_to_int(number): S2;
            S3 = i == 2 ? str_to_int(number): S3;
            S4 = i == 3 ? str_to_int(number): S4;
            number = "";
            q++;
        }
    T1 = S2 - S1;
    T2 = S3 - S2;
    T3 = S4 - S3;
    t = S3;
    tmp = abs((T2*T2)-(T1*T3));
    U += to_string(tmp) + " ";
    while (sequence[q] != '!')
    {
        T1 = T2;
        T2 = T3;
        S3 = S4;
        while(sequence[q] != ' ')
        {
            number += sequence[q];
            q++;
        }
        S4 = str_to_int(number);
        number = "";
        q++;
        T3 = S4 - S3; 
        tmp = abs((T2*T2)-(T1*T3));
        U += to_string(tmp) + " ";
    }
    return U + "!" + to_string(S1) + " " + to_string(S2) + " " + to_string(t) + " " + "*";
}

hacked_key hacking(string U)
{
    string number;
    int RESULT, q = 0, t1 = 0, t2 = 0, t3 = 0;
    while(U[q] != ' ')
    {
        number += U[q];
        q++;
    }
    t1 = str_to_int(number);
    number = "";
    q++;
    while(U[q] != '!')
    {
        while(U[q] != ' ')
        {
            number += U[q];
            q++;
        }
        t2 = str_to_int(number);
        number = "";
        RESULT = gcd(t1,t2);
        t1 = RESULT;
        q++;
    }
    q++;
    while(U[q] != ' ')
    {
        number += U[q];
        q++;
    }
    t1 = str_to_int(number);
    number = "";
    q++;
    while(U[q] != ' ')
    {
        number += U[q];
        q++;
    }
    t2 = str_to_int(number);
    number = "";
    q++;
    while(U[q] != ' ')
    {
        number += U[q];
        q++;
    }
    t3 = str_to_int(number);
    number = "";
    q++;
    if (U[q] == '*')
    {
        cout << "Success!" << endl;
    } else {
        cout << "No seq ending!" << endl;
        cout << U[q] << endl;
        return {0,0,0};
    }
    int i,j;
    for (i = 1; i < RESULT; i++)
    {
        int P1 = 0, P2 = 0;
        for (j = 1; j < RESULT; j++)
        {
            
            P1 = (i * t1 + j) % RESULT;
            P2 = (i * t2 + j) % RESULT;
            if ((t2 == P1) && (t3 == P2))
            {
                break;
            }
        }
        if ((t2 == P1) && (t3 == P2))
        {
            break;
        }
    }
    return {i,j,RESULT};
}
#include "../inc/create_seq.h"
    
int random (int min, int max)
{
    int Q;
    mt19937 gen(time(0));
    uniform_int_distribution<> dist(min, max);
    Q = dist(gen);
    return Q;
}

//Определяем значение остатка для заданного числа
string sequence_creator(int length)
{
    string Result = "";
    int Sequence[length];
    for (int i = 0; i < length; i++)
    {
        Sequence[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        if (random(0,1) == 0)
        {
            while (true)
            {
                int Qurent = random(65,90);
                int k = 0;
                while (!((Sequence[k] == 0) || (Qurent == Sequence[k]) || (k == length)))
                {
                    k++;
                }
                if (Sequence[k] == 0)
                {
                    Sequence[k] = Qurent;
                    break;
                } else if (k == length)
                {
                    break;
                }
            }
        } else {
            while (true)
            {
                int k = 0;
                int Qurent = random(97,122);
                while (!((Sequence[k] == 0) || (Qurent == Sequence[k]) || (k == length)) )
                {
                    k++;
                }
                if (Sequence[k] == 0)
                {
                    Sequence[k] = Qurent;
                    break;
                } else if (k == length)
                {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        Result += (char) Sequence[i];
    }
    return Result;
}
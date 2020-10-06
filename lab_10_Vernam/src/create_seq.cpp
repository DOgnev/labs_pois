#include "../inc/create_seq.h"
    
int random (int min, int max)
{
    int number;
    mt19937 gen(time(0));
    uniform_int_distribution<> dist(min, max);
    number = dist(gen);
    return number;
}

//Определяем последовательность. Последовательность представлена неповторяющимеся символами A-Za-z.
string sequence_creator(int length)
{
    string result = "";
    int sequence[length];
    for (int counter = 0; counter < length; counter++)
    {
        sequence[counter] = 0;
    }
    for (int counter = 0; counter < length; counter++)
    {
        if (random(0,1) == 0)
        {
            while (true)
            {
                int qurent = random(65,90);
                int counter = 0;
                while (!((sequence[counter] == 0) || (qurent == sequence[counter]) || (counter == length)))
                {
                    counter++;
                }
                if (sequence[counter] == 0)
                {
                    sequence[counter] = qurent;
                    break;
                } else if (counter == length)
                {
                    break;
                }
            }
        } else 
        {
            while (true)
            {
                int counter = 0;
                int qurent = random(97,122);
                while (!((sequence[counter] == 0) || (qurent == sequence[counter]) || (counter == length)) )
                {
                    counter++;
                }
                if (sequence[counter] == 0)
                {
                    sequence[counter] = qurent;
                    break;
                } else if (counter == length)
                {
                    break;
                }
            }
        }
    }
    for (int counter = 0; counter < length; counter++)
    {
        result += (char) sequence[counter];
    }
    return result;
}
//Функция проверки длины строки, если строка более 40 символов, тогда генерируем новую несколько раз.
string prevalidation (int length)
{
    int counter;
    string resolve="";
    if (length / 40 == 0)
    {
        return sequence_creator(length);
    } else 
    {
        for (counter = 0; counter < length / 40; counter++)
        {
            resolve += sequence_creator(40);
        }
        resolve += sequence_creator(length % 40);
        return resolve;
    }
}
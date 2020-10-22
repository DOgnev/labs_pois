//Модуль вспомогательных функций. 
#include "../inc/resolve.h"

bool DEBUG_RESOLVE = false;

//Функция проверки число на простоту
bool isSimple(int number)
{
    if ((number % 2) == 0) return false; // Если число четное, то 
    for (int counter = 3; counter < round(sqrt(number)); counter += 2) 
    {
        if (number % counter == 0)
        {
            return false;
        }
    }
    return true;
};

int computeRandom(int delta)
{
    mt19937 gen(time(0));
    uniform_int_distribution<> dist(3, delta); // Определяем диапазон значений 
    int number = dist(gen);
    Sleep(1000);
    return number;
}

int computeRandomFromZero(int delta)
{
    mt19937 gen(time(0));
    uniform_int_distribution<> dist(0, delta); // Определяем диапазон значений 
    int number = dist(gen);
    return number;
}

int computeSimpleRandom(int delta)
{
    int number = computeRandom(delta);
    // Крутим генератор, пока не находим простое число
    while(!isSimple(number))
    {
        number = computeRandom(delta);
    }
    return number;
}

void swapDigits(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void showArray(int inputArray[], int arrayLength)
{
    cout << "[showArray]: Executed array preview" << endl;
    for(int i = 0; i < arrayLength; i++)
    {
        cout << "[showArray]: Element " << i << " : " << inputArray[i] << endl;
    }
}

void computeRandomArray(int inputArray[], int arrayLength)
{
    for(int i = arrayLength - 1; i > 0; i--)
    {
        int j = computeRandom(100) % (i + 1);
        swapDigits(&inputArray[i], &inputArray[j]);
    }
}

void dragonRun (int number, bool success)
{
SetConsoleCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);
if(!success){
    system("cls"); 
    cout << "───────────████████     " << endl;
    cout << "──────────███▄███████   " << endl;
    cout << "──────────███████████    ===========================================    " << endl;
    cout << "──────────███████████  ======                                     ======" << endl;
    cout << "──────────██████      //Wait for a minute i am searching what you need\\" << endl;
    cout << "──────────█████████    ======                                     ======" << endl;
    cout << "█───────███████          ===========================================    " << endl;
    cout << "██────████████████      " << endl;
    cout << "███──██████████──█      " << endl;
    cout << "███████████████         " << endl;
    cout << "███████████████         " << endl;
    cout << "─█████████████          " << endl;
    cout << "──███████████           " << endl;
    cout << "────████████            " << endl;
    cout << "─────███──██            " << endl;
    cout << "─────██────██           " << endl;
    cout << "─────█                  " << endl;
    cout << "─────██                 " << endl;
    Sleep(800);
    system("cls");
    cout << "───────────████████     " << endl;
    cout << "──────────███▄███████   " << endl;
    cout << "──────────███████████    ===========================================        " << endl;
    cout << "──────────███████████  ======                                     ======    " << endl;
    cout << "──────────██████      //I found something, look is'it it? Dino founds this: " << number << " \\"<< endl;
    cout << "──────────█████████    ======                                     ======    " << endl;
    cout << "█───────███████          ===========================================        " << endl;
    cout << "██────████████████      " << endl;
    cout << "███──██████████──█      " << endl;
    cout << "███████████████         " << endl;
    cout << "███████████████         " << endl;
    cout << "─█████████████          " << endl;
    cout << "──███████████           " << endl;
    cout << "────████████            " << endl;
    cout << "─────███──██            " << endl;
    cout << "─────██───█            " << endl;
    cout << "─────███──█            " << endl;
    cout << "──────────██           " << endl;
    cout << endl;
    cout << endl;
    Sleep(200);
} else {
    system("cls");
    cout << "───────────████████     " << endl;
    cout << "──────────███▄███████   " << endl;
    cout << "──────────███████████    ===========================================        " << endl;
    cout << "──────────███████████  ======                                     ======    " << endl;
    cout << "──────────█████████      //I glad to help you! Have a nice day!           \\"<< endl;
    cout << "──────────██████       ======   Dino founds all you searching for ======    " << endl;
    cout << "█───────███████          ===========================================        " << endl;
    cout << "██────████████████      " << endl;
    cout << "███──██████████──█      " << endl;
    cout << "███████████████         " << endl;
    cout << "███████████████         " << endl;
    cout << "─█████████████          " << endl;
    cout << "──███████████           " << endl;
    cout << "────████████            " << endl;
    cout << "─────███──██            " << endl;
    cout << "─────██───█            " << endl;
    cout << "─────██ ──█            " << endl;
    cout << "─────███──██           " << endl;
    cout << endl;
    cout << endl;
    Sleep(200);
}
}
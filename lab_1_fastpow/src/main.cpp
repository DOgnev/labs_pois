﻿#include "../inc/fastpow.h"

bool DEBUG_MAIN = false; // чекер дебага

int main()
{
    int base = 1, index = 1, divisor = 1, result = 1;
    cout << "Enter base" << endl;
    // Получаем основание   
    cin >> base; 
    cout << "Enter index" << endl;
    // Получаем показатель
    cin >> index;
    cout << "Enter divisor" <<endl;
    // Получаем делитель
    cin >> divisor;
    // Вычисляем
    result = fastpow(base, index, divisor);
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: base= " << base << endl : cout << "";
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: index= " << index << endl : cout << "";
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: divisor= " << divisor << endl : cout << "";
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    cout << "[MAIN]: result = " << result << endl;  
    system("pause");
    return 0;
}
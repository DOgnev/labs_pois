#ifndef CARD_DRAW_PROTOCOL_H
#define CARD_DRAW_PROTOCOL_H

#include "resolve.h"
#include "fastPow.h"

using namespace std;

struct mandatoryClientData 
{     
    int mainDivisor = 4; // Первичный делитель P
    int secondaryDivisor = 4; // Вторичный делитель Q
    int privateKey = 1; // Закрытый ключ Phi
    int publicKey = 1; // Открытый ключ N
    int aliceSessionKey = 1; // Сессионный ключ Ca
    int aliceSessionKeyInvertion = 1;// Инверсия сессионного ключа Da по модулю (Phi) 
    int bobSessionKey = 1; // Сессионный ключ K
    int bobSessionKeyInvertion = 1;// Инверсия сессионного ключа K по модулю (Phi)   
};

class internalClientData 
{
    private:
    int curentDelta;
    mandatoryClientData clientData;

    bool isValid(int number, int maxValue, bool isGcdCheck = false, bool isGcdInverse = false, int gcdValue = 0, bool isPowCheck = false, int powArgument = 0)
    {
        bool result = false;
        result = ((number > 0) && (number < maxValue)) ? true : false;
        if (isPowCheck)
        {
            result = (fastPow(number,powArgument,maxValue) != 1) ? true : false;
        }
        if (isGcdCheck)
        {
            if(isGcdInverse)
            {
                result = (extendGcd(maxValue,number).gcd != gcdValue) ? true : false;
                isGcdInverse = false;
            } else
            {
                result = (extendGcd(maxValue,number).gcd == gcdValue) ? true : false;
            }
        }
        return result;
    }
    
    void initializeData()
    {
        //Ищем пару Q и P, такие, что P = 2 * Q + 1 и P, Q - простые
        while(!(isSimple(clientData.mainDivisor) && clientData.mainDivisor > 1 && clientData.secondaryDivisor > 1))
        {
            clientData.secondaryDivisor = computeSimpleRandom(curentDelta);
            clientData.mainDivisor = 2 * clientData.secondaryDivisor + 1;
            dragonRun(clientData.secondaryDivisor, false);
        }
        //Генерируем частный ключ Phi
        clientData.privateKey = (clientData.mainDivisor - 1) * (clientData.secondaryDivisor - 1);
        //Генерируем публичный ключ N
        clientData.publicKey = clientData.mainDivisor * clientData.secondaryDivisor;
        //Генерируем сессионный ключ C 0 < C < Phi - 1 и gcd(C, Phi - 1) = 1
        while(!((clientData.aliceSessionKey != clientData.bobSessionKey) && (clientData.aliceSessionKeyInvertion != clientData.aliceSessionKey) && (clientData.bobSessionKey != clientData.aliceSessionKeyInvertion)))
        {
            clientData.aliceSessionKey = 4;
            clientData.bobSessionKey = 4;
            while(!(isValid(clientData.aliceSessionKey, clientData.privateKey, true, false, 1)))
            {
                clientData.aliceSessionKey = computeRandom(clientData.privateKey);
                dragonRun(clientData.aliceSessionKey, false);
            }
            while(!(isValid(clientData.bobSessionKey, clientData.privateKey, true, false, 1)))
            {
                clientData.bobSessionKey = computeRandom(clientData.privateKey);
                dragonRun(clientData.bobSessionKey, false);
            }
        //Расчитываем инверсию D сессионного ключа
        clientData.aliceSessionKeyInvertion = extendGcd(clientData.privateKey, clientData.aliceSessionKey).numberInvertion;
        clientData.bobSessionKeyInvertion = extendGcd(clientData.privateKey, clientData.bobSessionKey).numberInvertion;
        clientData.aliceSessionKeyInvertion = clientData.aliceSessionKeyInvertion < 0 ? clientData.aliceSessionKeyInvertion + clientData.privateKey : clientData.aliceSessionKeyInvertion;
        clientData.bobSessionKeyInvertion = clientData.bobSessionKeyInvertion < 0 ? clientData.bobSessionKeyInvertion + clientData.privateKey : clientData.bobSessionKeyInvertion;
        }
    }

    public:
    internalClientData()
    {
        curentDelta = 125;
        initializeData();
        dragonRun(0, true);
        showAllParams();
        } 
    //Определяет диапазон генерации случайного числа, где delta - верхняя граница генерации - 1;
    void setRandomDelta(int newDeltaValue)
    {
        curentDelta = newDeltaValue;
        initializeData();
        showAllParams();
    }

    //Доступ к сгенерированным параметрам
    int getSecondaryDivisor() { return clientData.secondaryDivisor; } //Возвращаем делитель Q
    int getMainDivisor() { return clientData.mainDivisor; } //Возвращаем делитель P
    int getPrivateKey() { return clientData.privateKey; } //Возвращаем частный ключ Phi
    int getPublicKey() { return clientData.publicKey; } //Возвращаем публичный ключ N
    int getAliceSessionKey() { return clientData.aliceSessionKey; } //Возвращаем сессионный ключ Ca
    int getAliceSessionKeyInverse() { return clientData.aliceSessionKeyInvertion; } //Возвращает инверсию сессионного ключа Da
    int getBobSessionKey() { return clientData.bobSessionKey; } //Возвращаем сессионный ключ Cb
    int getBobSessionKeyInverse() { return clientData.bobSessionKeyInvertion; } //Возвращает инверсию сессионного ключа Db
    void showAllParams() {
        cout << "Params:" << endl;
        cout << "SecondaryDivisor Q: "<< clientData.secondaryDivisor << endl;
        cout << "MainDivisor P: "<< clientData.mainDivisor << endl;
        cout << "PrivateKey Phi: "<< clientData.privateKey << endl;
        cout << "PublicKey N: "<< clientData.publicKey << endl;
        cout << "AliceSessionKey Ca: "<< clientData.aliceSessionKey << endl;
        cout << "AliceSessionKeyInverse Da: "<< clientData.aliceSessionKeyInvertion << endl;
        cout << "BobSessionKey Cb: "<< clientData.bobSessionKey << endl;
        cout << "BobSessionKeyInverse Db: "<< clientData.bobSessionKeyInvertion << endl;
    }
};

void computeArrayImage(int inputCards[], int inputCardsReplica[], int realCardsLength, int delta); //Рандомим образы
int encryptRSA(int message, internalClientData encryptData, bool isAlice); // Шифруем число
int decryptRSA(int encrypt, internalClientData encryptData, bool isAlice); // Дешифруем число
void encryptArrayRSA(int inputArray[], int arrayLength, internalClientData encryptData, bool isAlice); // Шифруем массив
void decryptArrayRSA(int inputArray[], int arrayLength, internalClientData encryptData, bool isAlice); // Дешифруем массив
void cardDrawing(); //Реализация протокола ментального покера

#endif
#include "../inc/cardDrawProtocol.h"


void computeArrayImage(int inputCards[], int inputCardsReplica[], int realCardsLength, int delta)
{
    inputCards[0] = computeRandom(delta);
    inputCardsReplica[0] = inputCards[0];
    for(int i = 1; i < realCardsLength; i++)
    {
        inputCards[i] = computeRandom(delta);
        while(inputCards[i] == inputCards[i - 1])
        {
            inputCards[i] = computeRandom(delta);
        }
        inputCardsReplica[i] = inputCards[i];
    }
}

int encryptRSA(int message, internalClientData encryptData, bool isAlice = true)
{
    return (isAlice) ? fastPow(message, encryptData.getAliceSessionKey(), encryptData.getPublicKey()) : fastPow(message, encryptData.getBobSessionKey(), encryptData.getPublicKey());
    
}

int decryptRSA(int encrypt, internalClientData encryptData, bool isAlice = true)
{
    return (isAlice) ? fastPow(encrypt, encryptData.getAliceSessionKeyInverse(), encryptData.getPublicKey()) : fastPow(encrypt, encryptData.getBobSessionKeyInverse(), encryptData.getPublicKey());
}

void encryptArrayRSA(int inputArray[], int arrayLength, internalClientData encryptData, bool isAlice = true)
{
    for (int i = 0; i < arrayLength; i++)
    {
        inputArray[i] = encryptRSA(inputArray[i], encryptData, isAlice);
    }
}

void decryptArrayRSA(int inputArray[], int arrayLength, internalClientData encryptData, bool isAlice = true)
{
    for (int i = 0; i < arrayLength; i++)
    {
        inputArray[i] = decryptRSA(inputArray[i], encryptData, isAlice);
    }
}

void cardDrawing()
{
    cout << "[cardDrawing]: Card drawing for 2 players: Alice and Bob." << endl;
    cout << "[cardDrawing]: Executing transmit environment" << endl;
    Sleep(3000);
    internalClientData encryptData;
    string realCards[] = {"King", "Queen", "Soldier"};
    int realCardsLength = sizeof(realCards)/ sizeof(realCards[0]);
    int cardsImage[realCardsLength]; 
    int realCardsReplica[realCardsLength];
    computeArrayImage(cardsImage, realCardsReplica, realCardsLength, encryptData.getPublicKey());
    showArray(cardsImage, realCardsLength);
    cout << "[cardDrawing]: There is 3 cards in game:" << endl;
    for (int i = 0; i < realCardsLength; i++)
    {
        cout << i + 1 << " : " << realCards[i] << " it's image is " << realCardsReplica[i] << " " << endl; 
    }
    cout << "[cardDrawing]: Executing is successfull. Alice hangs the deck out." << endl;
    encryptArrayRSA(cardsImage, realCardsLength, encryptData,true); //Шифруем образы
    showArray(cardsImage, realCardsLength);
    computeRandomArray(cardsImage, realCardsLength); //Перемешиваем образы
    showArray(cardsImage, realCardsLength);
    cout << "[cardDrawing]: Encryption is successes, transmiting cards." << endl;
    cout << "[cardDrawing]: There is choosen one by Bob." << endl;
    int choosenCard = computeRandom(100) % realCardsLength; //Рандомим выбор карты Бобом
    cout << "[cardDrawing]: Bob have choose the " << choosenCard << " card" << endl;
    cout << "[cardDrawing]: Alice recieved her card, decoding" << endl;
    //Забираем Алисе выбранную Бобом карту и определяем ее
    int aliceRecievedCard = decryptRSA(cardsImage[choosenCard], encryptData, true);
    for (int i = 0; i < realCardsLength; i++)
    {
        if(aliceRecievedCard == realCardsReplica[i])
        {
            cout << "[cardDrawing]: Alice takes the " << realCards[i] << " card." <<endl;
            break;
        }
    }
    int cardsImageWithoutAlice[realCardsLength - 1];
    //Удаляем карту из массива
    cout << "[cardDrawing]: Bob discharges Alice's card froam board." << endl;
    int j = 0;
    for (int i = 0; i < realCardsLength; i++)
    {
        if (choosenCard != i)
        {
            cardsImageWithoutAlice[j] = cardsImage[i];
            j++;
        }
    }
    showArray(cardsImageWithoutAlice, realCardsLength - 1);
    cout << "[cardDrawing]: Bob parse and hangs the deck out" << endl;
    //Шифруем, перемешиваем и скидываем Алисе
    encryptArrayRSA(cardsImageWithoutAlice, realCardsLength - 1, encryptData,false); //Шифруем образы
    showArray(cardsImageWithoutAlice, realCardsLength - 1);
    computeRandomArray(cardsImageWithoutAlice, realCardsLength - 1);
    showArray(cardsImageWithoutAlice, realCardsLength - 1);
    choosenCard = computeRandom(100) % (realCardsLength - 1); //Рандомим выбор карты Алисой
    cout << "[cardDrawing]: Alice have choose the " << choosenCard << " card" << endl;
    cout << "[cardDrawing]: Bob recieved her card, decoding" << endl;
    //Забираем Бобу выбранную Алисой карту и определяем ее
    int bobRecievedCard = decryptRSA(decryptRSA(cardsImageWithoutAlice[choosenCard], encryptData, true), encryptData, false);
    for (int i = 0; i < realCardsLength; i++)
    {
        if(bobRecievedCard == realCardsReplica[i])
        {
            cout << "[cardDrawing]: Bob takes the " << realCards[i] << " card." <<endl;
            break;
        }
    }
}
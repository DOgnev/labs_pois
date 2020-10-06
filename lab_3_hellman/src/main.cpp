#include "../inc/hellman.h"

bool DEBUG_MAIN = false;

int main()
{
    data input;
    //Ожидание входных данных
    cout << "[MAIN]: Resolving." << endl;
    //Определение параметров. Вычисление ответа.
    input = resolve(input);
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: divisor= " << input.divisor << endl : cout << endl;
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: base= " << input.base << endl : cout << endl;
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: Xa= " << input.Xa << endl : cout << endl;
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: Xb= " << input.Xb << endl : cout << endl;
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: Ya= " << input.Ya << endl : cout << endl;
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: Yb= " << input.Yb << endl : cout << endl;
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: Zab= " << input.Za << endl : cout << endl;
    (DEBUG_MAIN == true) ? cout << "[DEBUG|MAIN]: Zba= " << input.Zb << endl : cout << endl;
    //--------------------СЕКЦИЯ ДЕБАГА ----------------------------//
    if (input.Za == input.Zb) cout << " [MAIN]: Transmition is success." << endl;
    else cout << " [MAIN]: Transmition is failed." << endl;
    system("pause");
    return 0;
}
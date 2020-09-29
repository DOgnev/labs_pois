#include "../inc/hellman.h"

bool DEBUG_MAIN = false;

int main()
{
    data Input;
     //Функция динамической рандомизации
    //Ожидание входных данных
    cout << "Resolving" << endl;
    Input = resolving(Input);
    cout << " [Main] Argument P = " << Input.argument_p << endl;
    cout << " [Main] Argument G = " << Input.argument_g << endl;
    cout << " [Main] Argument Xa = " << Input.Xa << endl;
    cout << " [Main] Argument Xb = " << Input.Xb << endl;
    cout << " [Main] Argument Ya = " << Input.Ya << endl;
    cout << " [Main] Argument Yb = " << Input.Yb << endl;
    cout << " [Main] Argument Za = " << Input.Za << endl;
    cout << " [Main] Argument Zb = " << Input.Zb << endl;
    if (Input.Za == Input.Zb)
    {
        cout << " [Main] Transmition is success" << endl;
    } else 
    {
        cout << " [Main] Transmition is failed" << endl;
    }
    system("pause");
    return 0;
}
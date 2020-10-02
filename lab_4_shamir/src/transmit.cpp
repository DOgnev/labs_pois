#include "../inc/transmit.h"

bool DEBUG_TRANSMIT = true;

int transmit(int message, data input)
{
    int step_1, step_2, step_3, step_4;
    while(true)
    {
        step_1 = fastpow(message, input.Ca, input.divisor);
        step_2 = fastpow(step_1, input.Cb, input.divisor);
        step_3 = fastpow(step_2, input.Da, input.divisor);
        step_4 = fastpow(step_3, input.Db, input.divisor);
        
        cout << "Transmitting A to B [itter 1]. step_1: "<< step_1 << endl;
        cout << "Transmitting B to A [itter 2]. step_2: "<< step_2 << endl;
        cout << "Transmitting A to B [itter 3]. step_3: "<< step_3 << endl;
        cout << "Solve message [itter 4]. step_4: "<< step_4 << endl;

        if (DEBUG_TRANSMIT == true)
        {
            (DEBUG_TRANSMIT == true) ? cout << "[DEBUG transmit]: message= " << message << endl : cout << endl;
            (DEBUG_TRANSMIT == true) ? cout << "[DEBUG transmit]: step_1= " << step_1 << endl : cout << endl;
            (DEBUG_TRANSMIT == true) ? cout << "[DEBUG transmit]: step_2= " << step_2 << endl : cout << endl;
            (DEBUG_TRANSMIT == true) ? cout << "[DEBUG transmit]: step_3= " << step_3 << endl : cout << endl;
            (DEBUG_TRANSMIT == true) ? cout << "[DEBUG transmit]: step_4= " << step_4 << endl : cout << endl;
        }

        if (step_4 == message)
        {
            cout << "Transmit Succesfull" << endl;
            return step_4;
        } else {
            cout << "Transmit failed" << endl;
              input = resolve(input);
        }
    }
}
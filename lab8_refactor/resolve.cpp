#ifndef RESOLVE_CPP
#define RESOLVE_CPP

#include "include.cpp"

//Чекер для дебага
bool DEBUG_RESOLVE = false;

struct data
{
    int X = 1;
    int Y = 1;
    int K = 1;
    int argument_g = 1;
    int argument_q = 1;
    int argument_p = 1;
    ext_nod_exit exit;
    
};

struct transmit_data
{
    unsigned int A;
    int B;
};

data resolving(data Input, int delta)
{
    srand(time(0));
    bool checker = false;
    Input.argument_q = random_simple(delta); 
    Input.argument_p = 2 * Input.argument_q + 1;
    while(!(simplecheck(Input.argument_p) == true))
    {
        Input.argument_q = random_simple(delta); 
        Input.argument_p = 2 * Input.argument_q + 1;
    }
    Input.argument_g = (2 + rand() % (Input.argument_p-1));
    if (DEBUG_RESOLVE == true)
    {
        cout << "[DEBUG_RESOLVE res]: g= " << Input.argument_g << endl;
        cout << "[DEBUG_RESOLVE res]: q= " <<  Input.argument_q  << endl;
        cout << "[DEBUG_RESOLVE res]: p= " <<  Input.argument_p  << endl;
    }
    while(!((Input.argument_g < Input.argument_p-1) && (Input.argument_g > 1) && (fastpow(Input.argument_g, Input.argument_q, Input.argument_p) != 1)))
    {
        Input.argument_g = (2 + rand() % (Input.argument_p-1));
    }

    Input.X = (2 + rand() % (Input.argument_p-1));
    while(!((Input.X < Input.argument_p) && (Input.X > 1)))
    {
        Input.X = (2 + rand() % (Input.argument_p-1));
    }
    Input.Y = fastpow(Input.argument_g,Input.X,Input.argument_p);
    Input.K = (2 + rand() % (Input.argument_p-1));
    Input.exit = ext_nod(Input.argument_p-1,Input.K);
    while(!((Input.K < Input.argument_p-1) && (Input.K > 1) && ext_nod(Input.argument_p-1,Input.K).nod == 1))
    {
        Input.K = (2 + rand() % (Input.argument_p-1));
        Input.exit = ext_nod(Input.argument_p-1,Input.K);
    }
    
    if (DEBUG_RESOLVE == true)
    {
        cout << "[DEBUG_RESOLVE res]: g= " << Input.argument_g << endl;
        cout << "[DEBUG_RESOLVE res]: p= " <<  Input.argument_p  << endl;
        cout << "[DEBUG_RESOLVE res]: K= " <<  Input.K  << endl;
        cout << "[DEBUG_RESOLVE res]: K_inv= " <<  Input.exit.x  << endl;  
        cout << "[DEBUG_RESOLVE res]: X= " <<  Input.X  << endl; 
        cout << "[DEBUG_RESOLVE res]: Y= " <<  Input.Y  << endl; 
    }
    return Input;
}

#endif

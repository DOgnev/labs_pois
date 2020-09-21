#include "include.cpp"

using namespace std;

#include "fastpow.cpp"
#include "randomize_and_check.cpp"
#include "ext_gdr.cpp"
#include "create_sign.cpp"
#include "resolve.cpp"
#include "encrypt_and_decrypt.cpp"


//Чекер для дебага
bool DEBUG = false;

int KEY = 11;

struct message
{
    string Input;
    string Output;
};

unsigned int transmit_sign(int h_B,int h_A, data Input_sign)
{
    transmit_data Sign;
    unsigned int h_res = 1, h_exp = 1;
    Sign.A = fastpow(Input_sign.argument_g, Input_sign.K, Input_sign.argument_p);
    Sign.B = ((h_B - (Input_sign.X * Sign.A)) * Input_sign.exit.x) % (Input_sign.argument_p - 1);
    if (Sign.B < 0)
    {
        Sign.B += (Input_sign.argument_p);   
    }
    cout << "Transmiting Sign from A to B" << endl;
    h_res = (fastpow(Input_sign.Y, Sign.A, Input_sign.argument_p) * fastpow(Sign.A, Sign.B, Input_sign.argument_p)) % Input_sign.argument_p;
    h_exp = fastpow(Input_sign.argument_g,h_A,Input_sign.argument_p);
    if (h_res == h_exp)
    {
        cout << "Sign Transmiting Success" << endl;
        return h_A;
    } else {
        cout << "Sign Transmiting Failed" << endl;
        cout << "Sign Transmiting Failed h_res= " << h_res << endl;
        cout << "Sign Transmiting Failed h_exp= " << h_exp << endl;
        return 1;
    }
}

struct transmit_message
{
    int A;
    int B;
};

int transmit(int m, data Input)
{
    transmit_data hash;
    transmit_message Message;
    data Input_sign = resolving(Input_sign, 0);
    unsigned int w = 1;
    int divisor_a = 1, divisor_b = 1;
    unsigned int sa = 1, sb = 1; 
    int m_res;
    Message.A = fastpow(Input.argument_g, Input.K, Input.argument_p);
    Message.B = (fastpow(Input.Y,Input.K,Input.argument_p) * (m % Input.argument_p)) % Input.argument_p;
    cout << "Transmiting Data from A to B" << endl;
    m_res = ((Message.B % Input.argument_p) * fastpow(Message.A,(Input.argument_p - 1 - Input.X),Input.argument_p)) % Input.argument_p;
    hash.B = Sign(m, KEY);
    hash.A = Sign(m_res, KEY);
    sb = hash.B;
    sa = hash.A;
    if (DEBUG == true)
    {
        cout << "[DEBUG transmit SIGN]: hA= " << hash.A << endl;
        cout << "[DEBUG transmit SIGN]: hB= " << hash.B << endl;
    }
    while(sa != 0)
    {
        Input_sign = resolving(Input_sign, sa);
        if (sa < Input_sign.argument_p)
        {  
            w = transmit_sign(sb, sa, Input_sign);
            sb /= Input_sign.argument_p;
            sa /= Input_sign.argument_p;
            if (DEBUG == true)
            {
                cout << "[DEBUG transmit SIGN]: w= " << w << endl;
            }
        } else if (sa > Input_sign.argument_p) 
        {
            Input_sign = resolving(Input_sign, sa);
            if (DEBUG == true)
            {
                cout << "[DEBUG transmit SIGN]: w= " << w << endl;
                cout << "[DEBUG transmit SIGN]: sa= " << sa << endl;
                cout << "[DEBUG transmit SIGN]: sb= " << sb << endl;
                cout << "[DEBUG transmit SIGN]: divisor= " << divisor_a << endl;
                cout << "[DEBUG transmit SIGN]: divisor= " << divisor_b << endl;
            }
        }
    }
    if((m == m_res) && (w == hash.A))
    {
        cout << "Transmiting Success" << endl; 
    } else {
        cout << "Transmiting Failed" << endl;
    }
    return m_res;
}

string sender (string message)
{
    data Input = resolving(Input, 200);
    int divisor = 1;
    string  out = "";
    for(int i = 0; i < message.length(); i++)
    {
        int tmp = encrypt(message[i]);
        int tmp_out = 1;
        while(tmp != 0)
        {
            if (tmp < Input.argument_p)
            {
                tmp_out *= transmit(tmp,Input);
                tmp /= Input.argument_p;
                if (DEBUG == true)
                {
                    cout << "[DEBUG sender LAST ITTER]: tmp_out= " << tmp_out << endl;
                }
            } else if (tmp_out > Input.argument_p) 
            {
                divisor = search_divisor(tmp);
                if (divisor != 0)
                {
                    tmp /= divisor;
                    tmp_out *= transmit(divisor,Input);
                } else {
                    Input = resolving(Input, tmp);
                } 
                if (DEBUG == true)
                {
                    cout << "[DEBUG sender]: tmp_out= " << tmp_out << endl;
                    cout << "[DEBUG sender]: tmp= " << tmp << endl;
                    cout << "[DEBUG sender]: divisor= " << divisor << endl; 
                }
            }
        }
        out += decrypt(tmp_out);
    } 
    return out;       
}

int main()
{
    message Input_string;
    //Определение входных данных
    cout << "Enter message" << endl;
    cin >> Input_string.Input;
    Input_string.Output = sender(Input_string.Input);
    cout << Input_string.Output << endl;
    system("pause");
    return 0;
}
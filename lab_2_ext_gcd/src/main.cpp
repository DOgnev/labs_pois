#include "../inc/ext_gdr.h"

int main()
{
    ext_nod_exit RESULT;
    int c, m;
    bool DEBUG_MAIN = false;
    cout << "Solve d in: cd mod m = 1" << endl;
    cout << "Expect c " << endl;
    cin >> c;
    cout << "Expect m " << endl;
    cin >> m;
    if (m > 0 && c > 0)
    {
        if (m >= c)
        {
            RESULT = ext_nod(m,c);
            if (RESULT.a2 < 0)
            {
                RESULT.a2 += m;
            } 
        } else {
            RESULT = ext_nod(c,m);
            if (RESULT.a2 < 0)
            {
                RESULT.a2 += c;
            } 
        }
    } else {
        cout << "ERROR" << endl;
    }
    if (DEBUG_MAIN == true)
    {
        cout << "[DEBUG main]: c= " << c << endl;
        cout << "[DEBUG main]: m= " << m << endl;
        cout << " Result x [ext_nod]: " << RESULT.a2 << endl; 
        cout << " Result nod [ext_nod]: " << RESULT.a1 << endl;    
    }
    cout << " Result y [ext_nod]: " << RESULT.a3 << endl;
    system("pause");
    return 0;
}
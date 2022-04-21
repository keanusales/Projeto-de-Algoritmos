#include <iostream>
#include "ajuda.h"
using namespace std;
int main()
{
    char p1[99], p2[99], p3[99];
    cin.get(p1, 99);
    /*cin.ignore();
    cin.get(p2, 99);
    cout << compara(p1, p2) << endl;*/
    copia(p1, p3);
    cout << p3 << endl;
    inverso(p3, p3);
    cout << p3 << endl;
    cout << compara(p1, p3) << endl;
    cout << palin(p1) << endl;
}

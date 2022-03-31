#include <iostream>
#include "auxiliar.h"
using namespace std;
complexo inicio(double a, int b)
{
    complexo c;
    c.numerica = a;
    c.imaginar = b;
    return c;
}
void copia(complexo*c, double a)
{
    c -> numerica = a;
}
void soma(double a, double b)
{
    cout << "Esse e o resultado da soma: ";
    cout << a + b << "i" << endl;
}
void ehreal(double a, int b)
{
    if (b == 1) cout << "O numero e: " << a << ". Ele e real.";
    else cout << "O numero e: " << a << "i. Ele nao e real.";
}
void imprime(complexo c)
{
    cout << "Esse e o numero armazenado: ";
    cout << c.numerica;
    if (c.imaginar == 1) cout << "i" << endl;
}

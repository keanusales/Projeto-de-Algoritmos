#include <iostream>
#include "auxiliar.h"
using namespace std;
complexo inicio(double a, double b)
{
    complexo c;
    c.real = a;
    c.imag = b;
    return c;
}
void copia(complexo* a, complexo b)
{
    a -> real = b.real;
    a -> imag = b.imag;
}
complexo soma(complexo a, complexo b)
{
    complexo c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}
bool ehreal(complexo a)
{
    if (a.imag == 0) return true;
    else return false;
}
void imprime(complexo a)
{
    cout << "Esse e o numero armazenado: ";
    cout << a.real << " " << a.imag << endl;
}

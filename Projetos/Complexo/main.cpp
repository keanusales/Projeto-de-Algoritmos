#include <iostream>
#include "auxiliar.h"
using namespace std;
int main()
{
    complexo a, b, c, d;
    a = inicio(33.67, 17.987);
    imprime(a);
    b = inicio(35.48, 23.5);
    imprime(b);
    c = soma(a, b);
    imprime(c);
    d = inicio(44.6, 0);
    imprime(d);
    if (ehreal(d) == 1) copia(&d, b);
    imprime(d);
}

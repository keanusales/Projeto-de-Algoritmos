#include <iostream>
#include "auxiliar.h"
using namespace std;
int main()
{
    complexo c;
    c = inicio(33.67, 1);
    imprime(c);
    copia(&c, 25.98);
    imprime(c);
    soma(23.87, 43.5);
    ehreal(67, 1);
}

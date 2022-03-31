#include <iostream>
#include "conta.h"
using namespace std;
int main()
{
    conta c;
    c = inicializa(2155865, 2300);
    imprime(c);
    deposito(&c, 500);
    imprime(c);
    saque(&c, 1000);
    imprime(c);
}

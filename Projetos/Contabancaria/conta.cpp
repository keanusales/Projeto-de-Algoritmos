#include <iostream>
#include "conta.h"
using namespace std;
conta inicializa(int num, double sal)
{
    conta c;
    c.numero = num;
    c.saldo = sal;
    return c;
}
void deposito(conta*c, double sal)
{
    c -> saldo += sal;
}
void saque(conta*c, double sal)
{
    c -> saldo -= sal;
}
void imprime(conta c)
{
    cout << c.numero << " " << c.saldo << endl;
}

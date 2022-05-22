#include <iostream>
using namespace std;
int main()
{
    double base, b, e, v = 0;
    cout << "Digite a base: ";
    cin >> b;
    cout << "Digite o expoente: ";
    cin >> e;
    base = b;
    for(int i = 0; i < e; i++)
    {
        b = b * base;
    }
    cout << "O resultado e: " << b;
}
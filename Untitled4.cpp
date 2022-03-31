#include <iostream>
using namespace std;
int main()
{
    double base, b, e, v;
    cout << "Digite a base: ";
    cin >> b;
    cout << "Digite o expoente: ";
    cin >> e;
    v = b;
    for(int i = 1; i < e; i++)
    {
        base = b;
        for(int j = 1; j < v; j++)
        {
            b = b + base;
        }
    }
    cout << "O resultado e: " << b;
}

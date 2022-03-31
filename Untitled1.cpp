#include <iostream>
using namespace std;
int main()
{
    int n, i, v = 0;
    cout << "Digite o numero: ";
    cin >> n;
    for(i = 2; i < n; i++)
    {
        if (n%i == 0) {v = 1; break;}
    }
    if (v == 0) cout << "O numero e primo.";
    else
    {
        cout << "O numero nao e primo.\n";
        cout << "Os numeros divisores de n sao: ";
        for(i = 1; i <= n; i++)
        {
            if (n%i == 0) cout << i << " ";
        }
    }
}

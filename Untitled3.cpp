#include <iostream>
using namespace std;
int main()
{
    int n, i, j, d = 0, s = 0;
    cout << "Quantidade: ";
    cin >> n;
    for(i = 2; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            if (i%j == 0) d++;
            if (d == 3) break;
        }
        if (d == 2) s += i;
        d = 0;
    }
    cout << "Soma: " << s;
}

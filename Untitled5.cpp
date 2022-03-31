#include <iostream>
using namespace std;
int main()
{
    int n, i, aux, troca = 1;
    cout << "Digite o tamanho do vetor: ";
    cin >> n; double v[n];
    for(i = 0; i < n; i++)
    {
        cout << "Digite o termo " << i+1 << ": ";
        cin >> v[i];
    }
    while (troca == 1)
    {
        troca = 0;
        for (i = 0; i < n-1; i++)
        {
            if (v[i] > v[i+1])
            {
                troca = 1;
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
    cout << "Ordenadamente o vetor fica:";
    for(i = 0; i < n; i++)
    {
        cout << " " << v[i];
    }
}

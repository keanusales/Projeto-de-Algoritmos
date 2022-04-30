#include "ajuda.h"
#include <iostream>
using namespace std;
int main() {
  char a[999], b[999], c; int d;
  cout << "Digite uma palavra: ";
  cin.get(a, 999);
  cout << "A quantidade de vogais: " << vogais(a);
  cin.ignore();
  cout << endl << endl;
  cout << "Digite a palavra da troca: ";
  cin.get(a, 999);
  cout << "Digite a letra da troca: ";
  cin >> c;
  cout << "Digite a posição da troca: ";
  cin >> d;
  cout << "O resultado da troca: " << troca(a, c, d);
  cin.ignore();
  cout << endl << endl;
  cout << "Digite a frase para iniciar a busca: ";
  cin.get(a, 999);
  cin.ignore();
  cout << "Digite a palavra-chave da busca: ";
  cin.get(b, 999);
  cout << "O resultado da busca é: "; busca(a, b);
}

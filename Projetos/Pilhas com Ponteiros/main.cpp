#include "pilha.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
	int opcao;
	TipoPilha *Pilha;
	Pilha = InicioPilha();
	TornarVazia(Pilha);
	system("clear||cls");
	while (1) {
		cout << "1 - Empilhar um elemento\n";
		cout << "2 - Desempilhar um elemento\n";
		cout << "3 - Exibir a Pilha\n";
		cout << "4 - Tamanho da Pilha\n";
		cout << "5 - Tornar a Pilha vazia\n";
		cout << "6 - Inverter uma String\n";
		cout << "7 - Inverter/Converter String\n";
		cout << "8 - Sair do programa\n";
		cout << "Qual opcao voce escolhe? ";
		cin >> opcao;
		switch (opcao) {
	    case 1: { // inserir elemento na pilha
	      bool cont2 = 1; int valor;
	      while (cont2) {
	      	cin.clear(); cin.ignore();
	      	system("clear||cls");
	      	cout << "Qual o valor para ser empilhado? ";
					cin >> valor; if (cin.good()) cont2 = 0;
				} TipoItem x; x.Chave = valor;
				Empilha(x, Pilha); system("clear||cls");
	      cout << "Valor empilhado com sucesso!\n";
	      break;
			}
	    case 2: { // remover elemento da pilha
	      system("clear||cls");
	      TipoItem *x = Desempilha(Pilha);
	      if (x != NULL) {
	      	printf("%i desempilhado!\n", x->Chave);
	        free(x);
	      } else cout << "A pilha esta vazia!\n";
	      break;
	    }
	    case 3: // mostrar os valores da pilha
	      system("clear||cls");
	      cout << "Desempilhando: ";
	      Imprime(Pilha); cout << endl;
	      break;
	    case 4: { // mostra o tamanho da pilha
	      system("clear||cls");
	      int t = Tamanho(Pilha);
	      if (t == 0) cout << "A pilha esta vazia!\n";
	      else printf("Tamanho da pilha: %i\n", t);
	      break;
	    }
	    case 5: // torna a pilha vazia
	      TornarVazia(Pilha);
	      system("clear||cls");
	      cout << "A pilha ficou vazia.\n";
	      break;
	    case 6: { // inverte uma string
	      char str[999];
	      system("clear||cls");
	      cout << "String para ser invertida: ";
	      cin.ignore(); cin.get(str, 999);
	      printf("A string invertida: %s\n", Inverte(str));
	      break;
	    }
	    case 7: { // inverte e converte uma string
	      char str1[999], *str2;
	      system("clear||cls");
	      cout << "String a ser invertida/convertida: ";
	      cin.ignore(); cin.get(str1, 999);
	      str2 = Inverte(str1);
	      for (int i = 0; str2[i]!='\0'; i++)
	      	str2[i] = Converte(str2[i]);
	      printf("A string invertida/convertida: %s\n", str2);
	      break;
	    }
	    case 8: // abandona o programa
	      system("clear||cls");
	      cout << "Ate a proxima vez!\n";
	      exit(0);
	    default: { // caso entre com valor inválido
	    	cin.clear(); cin.ignore();
	    	system("clear||cls");
	    	cout << "Entrada invalida! Tente de novo.\n";
				break;
			}
	  }
	}
}
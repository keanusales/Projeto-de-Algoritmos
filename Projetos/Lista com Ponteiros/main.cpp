#include <iostream>
#include <cstdlib>
#include "lista.h"

using namespace std;

int main(void){
  int op;
  int valor;
  int ret = 0;
  TipoItem x; 
  Apontador E;
  E = (Apontador) malloc(sizeof(Celula));
  TipoLista* list;
  list = InicializaLista();
  FLVazia(list);
  while( 1 ){
		cout << "1 - Inserir elemento no inicio\n";
    cout << "2 - Inserir elemento no final\n";
		cout << "3 - Remover elemento\n";
		cout << "4 - Mostrar lista\n";
    cout << "5 - Consultar elemento\n";
    cout << "6 - Tamanho da lista\n";
    cout << "7 - Tornar a lista vazia\n";
		cout << "8 - Sair\n";
		cout << "Opcao? ";
		scanf( "%d", &op );
		switch( op ){
			case 1: // inserir elemento no inicio
				cout << "Qual o valor para ser inserido no inicio da lista? ";
				cin >> valor;
        x.Chave = valor;
        E = list->Primeiro;
        Insere (x, list, E);
        cout << "valor inserido com sucesso no inicio da lista" << endl << endl;
				break;
      case 2: // inserir elemento no final
				cout << "Qual o valor para ser inserido no final da lista? ";
				cin >> valor;
        x.Chave = valor;
        E = list->Ultimo;
        Insere (x, list, E);
        cout << "valor inserido com sucesso no final da lista" << endl << endl;
				break;
			case 3: // remover elemento no começo
        E = list->Primeiro;
        x =  RetiraIni(E, list);
        cout << "valor " << x.Chave << " removido da lista" << endl << endl;
				break;
			case 4: // mostrar os valores da lista
				Imprime(list);
				break;
			case 5: //  consulta por valor
        cout << "Qual o valor para consultar? ";
				cin >> valor;
        ret = Busca(valor, list);
        if(ret == 1){
          cout << "Valor " << valor << " encontrado na lista" << endl << endl;
        }else{
          cout << "Valor " << valor << " não encontrado na lista" << endl << endl;
        }
				break;
      case 6: //  tamanho da lista
        cout << "lista vazia?: " <<  Vazia(list) << endl;
        cout << "Tamanho da lista: " << Tamanho_lista(list)  << endl << endl;
        break;
      case 7: //  fazer lista vazia
        FLVazia(list);
        cout << "Lista ficou vazia" << endl << endl;
        break;
			case 8: // abandonar o programa
				exit(0);
		}
	}
}
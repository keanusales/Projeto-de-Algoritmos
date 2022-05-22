#include <iostream>
#include <cstdlib>
#include "lista.h"

using namespace std;

int main(void){
  int valor, op;
  int ret = 0;
  TipoLista* list;
  list = InicializaLista();
  FLVazia(list);
  while( 1 ){
		cout << "1 - Inserir elemento\n";
		cout << "2 - Remover elemento\n";
		cout << "3 - Mostrar lista\n";
    cout << "4 - Consultar elemento\n";
    cout << "5 - Tamanho da lista\n";
    cout << "6 - Tornar a lista vazia\n";
		cout << "7 - Sair\n";
		cout << "Opcao? ";
		scanf( "%d", &op );
		switch( op ){
			case 1: // inserir elemento
				cout << "Qual o valor para ser inserido? ";
				cin >> valor;
				TipoItem* item; 
        item = (TipoItem*) malloc(sizeof(TipoItem)); 
        item->valor = valor;
        Insere(item, list);
        cout << "valor inserido com sucesso na lista" << endl << endl;
				break;
			case 2: // remover elemento
        TipoItem* it; 
        it = (TipoItem*) malloc(sizeof(TipoItem)); 
        cout << "Qual a posicao entre [" << InicioVetor << " e " << list->Ultimo - 1 << "] para ser removido o elemento? ";
				cin >> valor;
        it = Retira(valor, list);
        cout << "valor " << it->valor << " removido da lista" << endl << endl;
				break;
			case 3: //  mostrar os valores da lista
				Imprime(list);
				break;
			case 4: //  consulta por valor
        cout << "Qual o valor para consultar? ";
				cin >> valor;
        ret = Busca(valor, list);
        if(ret == 1){
          cout << "Valor " << valor << " encontrado na lista" << endl << endl;
        }else{
          cout << "Valor " << valor << " não encontrado na lista" << endl << endl;
        }
				break;
      case 5: //  tamanho da lista
        cout << "lista vazia?: " <<  Vazia(list) << endl;
        cout << "Tamanho da lista: " << Tamanho_lista(list)  << endl << endl;
        break;
      case 6: //  fazer lista vazia
        FLVazia(list);
        cout << "Lista ficou vazia" << endl << endl;
        break;
			case 7: // abandonar o programa
				exit(0);
		}

	}
}
#include <iostream>
#include <cstdlib>
#include "lista.h"

using namespace std;

/* Inicializa uma lista */
TipoLista* InicializaLista(){
  TipoLista* lista = (TipoLista*)malloc(sizeof(TipoLista));
  return lista;
}

/* Faz a lista ficar vazia */
void FLVazia (TipoLista* Lista) {
  Lista->Primeiro = InicioVetor;
  Lista->Ultimo = Lista->Primeiro;
}

/*Verifica se a lista está vazia*/
int Vazia (TipoLista* Lista){
  return (Lista->Primeiro == Lista->Ultimo);
}

/* Insere x após o último elemento da lista */
void Insere (TipoItem* x, TipoLista *Lista) {
  if (Lista ->Ultimo >= MaxTam)
    cout << "Lista está cheia" << endl;
  else{
    Lista ->Item[Lista->Ultimo] = *x;
    Lista->Ultimo++;
  }
}

int Busca(int chave, TipoLista* lista){
  for(int i = 0; i < lista->Ultimo; i++){
    if(lista->Item[i].valor == chave){
      return 1;
      break;
    }else{
      return 0;
    }
  }
  return 0;
}

int Tamanho_lista(TipoLista* Lista){
  if (Lista == NULL)
    return -1;
  else
    return Lista->Ultimo;
}

/*Retorna o item x que está na posição p da lista,
retirando-o da lista e deslocando os itens a partir
da posição p+1 para as posições anteriores */
TipoItem* Retira (Posicao p, TipoLista* Lista) {
  int Aux;
  TipoItem* item;
  item = (TipoItem*) malloc(sizeof(TipoItem));
  if (Vazia(Lista) || p >= Lista->Ultimo){
    cout << "A posição não existe!" << endl;
    return NULL;
  }
  *item = Lista->Item[p];
  Lista->Ultimo--;
  for (Aux = p; Aux < Lista->Ultimo; Aux++)
    Lista->Item[Aux] = Lista->Item[Aux+1];
  return item;
}

/*Imprime os itens da lista na ordem de ocorrência */
void Imprime (TipoLista* Lista){
  if (Tamanho_lista(Lista) == 0){
    cout << "Lista vazia" << endl << endl;
  }else{
    cout << "Valores na lista" << endl;
    cout << "p - key" << endl;
      for (int Aux = Lista->Primeiro; Aux < Lista->Ultimo; Aux++){
        cout << Aux << " - " << Lista->Item[Aux].valor  << endl;
      }
      cout << endl;
  }
}

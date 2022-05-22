#include <iostream>
#include <cstdlib>>
#include "lista.h"

using namespace std;

/* Inicializa uma lista */
TipoLista* InicializaLista(){
  TipoLista* lista = (TipoLista*)malloc(sizeof(TipoLista));
  return lista;
}

/* Faz a lista ficar vazia */
void FLVazia (TipoLista* Lista) {
  Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
  Lista->Ultimo = Lista->Primeiro; 
  Lista->Primeiro->Prox = NULL;
}

/*Verifica se a lista está vazia*/
int Vazia (TipoLista* Lista){
  return (Lista->Primeiro == Lista->Ultimo); 
}

/* Insere x após o último elemento da lista */
void Insere (TipoItem x, TipoLista *Lista, Apontador E) {
  Apontador novo;
  novo = (Apontador) malloc(sizeof(Celula));
  novo->Item = x;
  novo->Prox = E->Prox;
  if(Lista->Primeiro->Prox == NULL)
    Lista->Ultimo = novo;
  if(Lista->Ultimo == E)
    Lista->Ultimo = novo;
  E->Prox = novo;
  
}

/*Retorna o item x que está na posição p da lista, retirando-o da lista e deslocando os itens a partir da posição p+1 para as posições anteriores */
TipoItem RetiraIni (Celula* cel, TipoLista *Lista) {
  Apontador lixo;
  lixo = (Apontador) malloc(sizeof(Celula));
  lixo = cel->Prox;
  cel->Prox = lixo->Prox;
  TipoItem item = lixo->Item;
  //cout << "teste " << lixo->Item.Chave << endl;
  if (Lista->Ultimo == lixo)
    Lista->Ultimo == Lista->Primeiro;
  free (lixo);
  return item;
}

/*Retorna o tamanho da lista  */
int Tamanho_lista (TipoLista* Lista){
  int count = 0;
  Apontador p = (Apontador) malloc(sizeof(Celula));
  if (Lista->Primeiro->Prox != NULL)
    for (p = Lista->Primeiro->Prox; p != NULL; p = p->Prox) {
		  count ++;
	  }
  return count;
}

/*Imprime os itens da lista na ordem de ocorrência  */
void Imprime (TipoLista* Lista){
  if (Lista->Primeiro->Prox == NULL)
    cout << "Lista vazia" << endl << endl;
  else{
    cout << "Valores na lista" << endl;
    Apontador p = (Apontador) malloc(sizeof(Celula));
    for (p = Lista->Primeiro->Prox; p != NULL; p = p->Prox) {
		  cout <<  p->Item.Chave << endl;
	  }
    cout << endl;
  }
}
int Busca(int chave, TipoLista* Lista){
  Apontador p = (Apontador) malloc(sizeof(Celula));
  for (p = Lista->Primeiro->Prox; p != NULL; p = p->Prox) {
    if(p->Item.Chave == chave){
      return 1;
      break;
    }else{
      return 0;
    }
	}
  return 0;
}
#include "pilha.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;
TipoPilha *InicioPilha() {
  TipoPilha *Pilha;
  Pilha = (TipoPilha*)malloc(sizeof(TipoPilha));
  return Pilha;
}
void TornarVazia(TipoPilha *Pilha) {
  Pilha->Topo = (Apontador)malloc(sizeof(Celula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
}
bool EstaVazia(TipoPilha *Pilha) {
  return (Pilha->Topo == Pilha->Fundo);
}
void Empilha(TipoItem x, TipoPilha *Pilha) {
  Apontador Aux;
  Aux = (Apontador)malloc(sizeof(Celula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
}
TipoItem *Desempilha(TipoPilha *Pilha) {
  if (EstaVazia(Pilha) == 1)
    return NULL;
  else {
    Apontador Aux;
    TipoItem *item;
    item = (TipoItem*)malloc(sizeof(TipoItem));
    Aux = Pilha->Topo;
    Pilha->Topo = Aux->Prox;
    *item = Pilha->Topo->Item;
    free(Aux);
    Pilha->Tamanho--;
    return item;
  }
}
int Tamanho(TipoPilha *Pilha) {
  return (Pilha->Tamanho);
}
void Imprime(TipoPilha *Pilha) {
  if (EstaVazia(Pilha) == 1)
    cout << "A pilha esta vazia!";
  else {
    Celula *Aux = Pilha->Topo->Prox;
    while (Aux != Pilha->Fundo->Prox) {
      cout << Aux->Item.Chave << " ";
      Aux = Aux->Prox;
    }
  }
}
char *Inverte(char *a) {
  static char b[999];
  TipoPilha *Pilha;
  Pilha = InicioPilha();
  TornarVazia(Pilha);
  int t, i, j, n = 0;
  for (t = 0; a[t] != '\0'; t++);
  for (i = 0; i <= t; i++) {
    if (a[i] == ' ' || a[i] == '\0') {
      TipoItem x, *y;
      for (j = n; j < i; j++) {
        x.Letra = a[j];
        Empilha(x, Pilha);
      }
      for (j = n; j < i; j++) {
        y = Desempilha(Pilha);
        b[j] = y->Letra;
      }
      TornarVazia(Pilha);
      b[i] = ' '; n = i + 1;
    }
  } b[t] = '\0'; free(Pilha); return b;
}
char Converte(char letra) {
	if ('a' <= letra && letra <= 'z')
		return letra - 'a' + 'A';
	else if ('A' <= letra && letra <= 'Z')
		return letra - 'A' + 'a';
	return letra;
}
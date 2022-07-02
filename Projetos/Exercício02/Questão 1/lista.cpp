#include "lista.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;
TipoLista *InicioLista() {
  TipoLista *Lista;
  Lista = (TipoLista*)malloc(sizeof(TipoLista));
  Esvaziar(Lista);
  return Lista;
}
void Esvaziar(TipoLista *Lista) {
  Lista->First = (Ponteiro)malloc(sizeof(Celula));
  Lista->Last = Lista->First;
  Lista->First->Ante = NULL;
  Lista->First->Prox = NULL;
}
bool EstaVazia(TipoLista *Lista) {
  return (Lista->First == Lista->Last);
}
void Insere(TipoItem x, TipoLista *Lista) {
  Ponteiro Aux = Lista->Last;
  Lista->Last->Prox = (Ponteiro)malloc(sizeof(Celula));
  Lista->Last = Lista->Last->Prox;
  Lista->Last->Ante = Aux;
  Lista->Last->Item = x;
  Lista->Last->Prox = NULL;
}
Ponteiro Busca(int x, TipoLista *Lista) {
  if (!EstaVazia(Lista)) {
    Ponteiro i;
    for (i = Lista->First->Prox; i != NULL; i = i->Prox)
      if (i->Item.telef == x) return i;
  } return NULL;
}
TipoLista *CopiaLista(TipoLista *Lista) {
  TipoLista *Aux = InicioLista(); Ponteiro i;
  for (i = Lista->First->Prox; i != NULL; i = i->Prox)
    Insere(i->Item, Aux);
  return Aux;
}
TipoItem Retira(Ponteiro Cel, TipoLista *Lista) {
  Cel->Ante->Prox = Cel->Prox;
  if (Cel->Prox == NULL) Lista->Last = Cel->Ante;
  else Cel->Prox->Ante = Cel->Ante;
  TipoItem Item = Cel->Item;
  free(Cel); return Item;
}
bool RetiraRep(TipoLista *Lista) {
  bool r = 0;
  if (!EstaVazia(Lista)) {
    Ponteiro i, j; TipoItem Item;
    for (i = Lista->First->Prox; i != NULL; i = i->Prox)
      for (j = i->Prox; j != NULL; j = j->Prox)
        if (i->Item.telef == j->Item.telef) {
          r = 1; Item = Retira(j, Lista);
          cout << "Contato duplicado removido:\n";
          printf("Nome: %s, Email: %s, Telefone: %i\n",
            Item.nome, Item.email, Item.telef);
        }
  } return r;
}
void Imprime(TipoLista *Lista) {
  if (!EstaVazia(Lista)) {
    Ponteiro i;
    for (i = Lista->First->Prox; i != NULL; i = i->Prox)
      printf("Nome: %s, Email: %s, Telefone: %i\n",
        i->Item.nome, i->Item.email, i->Item.telef);
  } else cout << "Não existem contatos!\n";
}
bool ImprimeRep(TipoLista *Lista) {
  bool r = 0;
  if (!EstaVazia(Lista)) {
    Ponteiro i, j; TipoItem Item;
    TipoLista *Aux = CopiaLista(Lista);
    for (i = Aux->First->Prox; i != NULL; i = i->Prox)
      for (j = i->Prox; j != NULL; j = j->Prox)
        if (i->Item.telef == j->Item.telef) {
          r = 1; Item = Retira(j, Aux);
          cout << "Item com contato duplicado:\n";
          printf("Nome: %s, Email: %s, Telefone: %i\n",
            Item.nome, Item.email, Item.telef);
        } free(Aux);
  } return r;
}
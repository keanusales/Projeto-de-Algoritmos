typedef struct {
  char nome[80];
  char email[80];
  int telef;
} TipoItem;

typedef struct Celula* Ponteiro;

typedef struct Celula {
  TipoItem Item;
  Ponteiro Ante, Prox;
} Celula;

typedef struct {
  Ponteiro First, Last;
} TipoLista;

TipoLista *InicioLista();
void Esvaziar(TipoLista*);
bool EstaVazia(TipoLista*);
void Insere(TipoItem, TipoLista*);
Ponteiro Busca(int, TipoLista*);
TipoLista* CopiaLista(TipoLista*);
TipoItem Retira(Ponteiro, TipoLista*);
bool RetiraRep(TipoLista*);
void Imprime(TipoLista*);
bool ImprimeRep(TipoLista*);
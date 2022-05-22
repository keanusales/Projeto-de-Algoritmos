typedef struct {
  int Chave;
  char Letra;
} TipoItem;

typedef struct Celula *Apontador;

typedef struct Celula {
  TipoItem Item;
  Apontador Prox;
} Celula;

typedef struct {
  Apontador Topo, Fundo;
  int Tamanho;
} TipoPilha;

TipoPilha *InicioPilha();
void TornarVazia(TipoPilha*);
bool EstaVazia(TipoPilha*);
void Empilha(TipoItem, TipoPilha*);
TipoItem *Desempilha(TipoPilha*);
int Tamanho(TipoPilha*);
void Imprime(TipoPilha*);
char *Inverte(char*);
char Converte(char);
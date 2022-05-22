//typedef int TipoChave;

typedef struct  {
  int Chave;
  /* outros componentes */
}TipoItem;


typedef struct Celula_str *Apontador;

typedef struct Celula_str{
  TipoItem Item;
  Apontador Prox;
} Celula;

typedef struct{
  Apontador Primeiro, Ultimo;
} TipoLista;

TipoLista* InicializaLista();
void FLVazia (TipoLista* ); 
int Vazia (TipoLista *);
void Insere (TipoItem , TipoLista *, Apontador); 
TipoItem RetiraIni (Celula*, TipoLista *); 
void Imprime (TipoLista* );
int Tamanho_lista(TipoLista* );
int Busca(int , TipoLista* );

//TODO: funções a serem implementadas
TipoItem* InicializaTipoItem();
void ModificaValorItem (TipoItem*, int ); 
void ImprimeTipoItem(TipoItem* );
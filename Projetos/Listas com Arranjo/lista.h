typedef int Posicao;
#define InicioVetor 0
#define MaxTam  1000

typedef struct tipoitem {
  int valor;
  /* outros componentes */
}TipoItem;

typedef struct tipolista{
  TipoItem Item[MaxTam];
  Posicao Primeiro, Ultimo;
}TipoLista;

TipoLista* InicializaLista();
void FLVazia (TipoLista* );
int Vazia (TipoLista* );
int Tamanho_lista(TipoLista* );
void Insere (TipoItem* , TipoLista* ); 
int Busca(int, TipoLista* );
TipoItem* Retira (Posicao, TipoLista* ); 
void Imprime (TipoLista* );

//TODO: funções a serem implementadas
TipoItem* InicializaTipoItem();
void ModificaValorItem (TipoItem* , int ); 
void ImprimeTipoItem(TipoItem* );
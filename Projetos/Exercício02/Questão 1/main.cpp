#include "lista.cpp"
#include <iostream>
#include <locale>
using namespace std;
int main(void) {
	setlocale(LC_ALL, "");
  int opcao;
  TipoLista *Lista;
  Lista = InicioLista();
  system("clear||cls");
  while (1) {
    cout << "1 - Incluir um novo contato\n"
      << "2 - Remover um contato pelo telefone\n"
      << "3 - Listar todos os contatos\n"
      << "4 - Buscar um contato pelo telefone\n"
      << "5 - Mostrar os telefones repetidos\n"
      << "6 - Apagar os telefones repetidos\n"
      << "7 - Sair do programa\n"
      << "Qual opção você escolhe? ";
    cin >> opcao;
    switch (opcao) {
    case 1: { // Inclui um contato na lista
      TipoItem x; system("clear||cls");
      cout << "Qual o nome do contato? ";
      cin.ignore(); cin.get(x.nome, 80);
      cout << "Qual o email do contato? ";
      cin.ignore(); cin.get(x.email, 80);
      cout << "Qual o telefone do contato? ";
      cin.ignore(); cin >> x.telef;
      Insere(x, Lista); system("clear||cls");
      cout << "Contato inserido com sucesso!\n";
      break;
    }
    case 2: { // Remove um contato pelo telefone
      system("clear||cls"); int t;
      cout << "Entre com o telefone desejado: ";
      cin >> t; Ponteiro r = Busca(t, Lista);
      if (r != NULL) {
        TipoItem Item = Retira(r, Lista);
        cout << "Segue o contato removido:\n";
        printf("Nome: %s, Email: %s, Telefone: %i\n",
          Item.nome, Item.email, Item.telef);
      } else cout << "Esse telefone não existe!\n";
      break;
    }
    case 3: // Lista todos os contatos
      system("clear||cls");
      cout << "A lista de todos os contatos:\n";
      Imprime(Lista);
      break;
    case 4: { // Busca um contato pelo telefone
      system("clear||cls"); int t;
      cout << "Entre com o telefone desejado: ";
      cin >> t; Ponteiro r = Busca(t, Lista);
      if (r != NULL)
        printf("Nome: %s, Email: %s, Telefone: %i\n",
          r->Item.nome, r->Item.email, r->Item.telef);
      else cout << "Esse telefone não existe!\n";
      break;
    }
    case 5: { // Mostra todos os contatos repetidos
      system("cls||clear");
      bool r = ImprimeRep(Lista);
      if (!r) cout << "Sem contatos repetidos!\n";
      break;
    }
    case 6: { // Remove todos os contatos repetidos
      system("cls||clear");
      bool r = RetiraRep(Lista);
      if (!r) cout << "Sem contatos repetidos!\n";
      break;
    }
    case 7: // Abandona o programa
      system("clear||cls");
      cout << "Até a próxima vez!\n";
      exit(0);
    default: // Casos de valores inválidos
      cin.clear(); cin.ignore();
      system("clear||cls");
      cout << "Valor Inválido! Tente de novo.\n";
      break;
    }
  }
}
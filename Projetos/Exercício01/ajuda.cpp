#include <iostream>
#include "ajuda.h"
using namespace std;
int vogais (char* a)
{
  int i, j, c = 0;
  int v1[5] = {'a', 'e', 'i', 'o', 'u'};
  int v2[5] = {'A', 'E', 'I', 'O', 'U'};
  for (i = 0; a[i]!='\0'; i++)
  {
    for (j = 0; j < 5; j++)
    {
      if (a[i] == v1[j] || a[i] == v2[j])
        c++;
    }
  }
  return c;
}
char* troca(char* a, char b, int c)
{
  a[c] = b; return a;
}
void busca(char* a, char* b)
{
  int l, i, j, c = 1;
  for (l = 0; b[l]!='\0'; l++);
  for (i = 0; a[i]!='\0'; i++)
  {
    if (a[i] == b[0])
    {
      for (j = 1; j < l; j++)
      {
        if (a[i+j] == b[j]) c++;
      }
    }
    if (c == l) cout << i << " ";
    c = 1;
  }
}

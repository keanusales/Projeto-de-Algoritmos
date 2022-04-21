#include <iostream>
#include "ajuda.h"
using namespace std;
bool digito(char a)
{
    if ((a >= '0') && (a <= '9'))
        return true;
    else return false;
}
bool maius(char a)
{
    if ((a >= 'A') && (a <= 'Z'))
        return true;
    else return false;
}
bool menus(char a)
{
    if ((a >= 'a') && (a <= 'z'))
        return true;
    else return false;
}
char ma_mi(char a)
{
    char r;
    r = a - 'A' + 'a';
    return r;
}
char mi_ma(char a)
{
    char r;
    r = a - 'a' + 'A';
    return r;
}
bool palin(char* a)
{
    int i, c = 0, v = true;
    while (a[c]!='\0') c++;
    for (i = 0; i < c; i++)
    {
        if (a[i] != a[c-i-1])
            v = false;
    }
    return v;
}
void copia(char* a, char* b)
{
    int i;
    for (i = 0; a[i]!='\0'; i++)
    {
        b[i] = a[i];
    }
    b[i] = '\0';
}
bool compara(char* a, char* b)
{
    int i;
    for (i = 0; a[i]!='\0' && b[i]!='\0'; i++)
    {
        if (a[i] != b[i]) return false;
    }
    if (a[i] == b[i]) return true;
    else return false;
}
char inverso(char* a, char* b)
{
    int i, c = 0;
    while (a[c]!='\0') c++;
    for (i = 0; i < c; i++)
    {
        b[i] = a[c-i-1];
    }
}

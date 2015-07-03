#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct no
{
    float coef;                              /*coeficiente*/
    int exp;                                 /*expoente*/
    struct no *proximo;                      /*sucessor do no*/
};
typedef struct no No;

No* criaLista();
No* insereInicio (No* l, float coef, int exp);
No* insereFim (No* l, float coef, int exp);
No* insereOrdenado (No* l, float coef, int exp);
No* removeNo (No* l, float coef);
void imprimeLista (No* l);
void destroiLista(No* l);
No* transformaString(char* str, No* lista);
void apagarParteString(char* str, int tam);
void copiaParteNumerica(char* str1, char* str2);
No* subtrairPolinomios(No* polinomio1, No* polinomio2);
void multiplicaPolinomio(No *l1,No *l2);
char* transformaPolinomio(No* polinomio);
No* dividirPolinomios(No* polinomio1, No* polinomio2);

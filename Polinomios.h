#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 20

struct no
{
    float coef;                              /*coeficiente*/
    int exp;                                 /*expoente*/
    struct no *proximo;                      /*sucessor do no*/
};
typedef struct no No;

struct resultadoDivisao
{
    struct no *quociente;
    struct no *resto;
};
typedef struct resultadoDivisao ResultadoDivisao;


ResultadoDivisao* criaResultadoDivisao();
No* criaLista();
No* insereInicio (No* l, float coef, int exp);
No* insereFim (No* l, float coef, int exp);
No* insereOrdenado (No* l, float coef, int exp);
No* removeNo (No* l, No *endereco);
void imprimeLista (No* l);
void destroiLista(No* l);
No* transformaString(char* str, No* lista);
void apagarParteString(char* str, int tam);
void copiaParteNumerica(char* str1, char* str2);
No* subtrairPolinomios(No* polinomio1, No* polinomio2);
No* multiplicaPolinomio(No *l1,No *l2);
No* simplificaPolinomio(No *l);
char* transformaPolinomio(No* polinomio);
ResultadoDivisao* dividirPolinomios(No* polinomio1, No* polinomio2);

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

struct noLOG{
    char* info;
    struct noLOG *proximo;
};typedef struct noLOG NoLOG;
/** Toda vez que fizer uma operacao nova, inserir o string do usuario ou resultado da operação (ex: Resultado=3x^2+2x) na lista LOG, no fim, quando usario requsitar o arquivo log, tudo da lista eh escrito e printado do arquivo. **/

NoLOG* criaLista(); /**Inicializar no main **/
NoLOG* InsereInicioLOG(NoLOG* l, char* info); /** Funcao nova **/
FILE* escreveLOG(FILE *log, NoLOG *l); /** Funcao nova **/
void imprimeLOG(FILE *log); /** Funcao nova **/

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

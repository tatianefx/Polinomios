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

struct noLOG{
    char* info;
    struct noLOG *proximo;
};typedef struct noLOG NoLOG;

No* criaLista();
No* insereInicio (No* l, float coef, int exp);
No* insereFim (No* l, float coef, int exp);
No* insereOrdenado (No* l, float coef, int exp);
No* removeNo (No* l, No *endereco);
void imprimeLista (No* l);
void destroiLista(No* l);
No* transformaString(char* str);
void apagarParteString(char* str, int tam);
void copiaParteNumerica(char* str1, char* str2);
No *somaPolinomio(No *l1,No *l2);
No* subtrairPolinomios(No* polinomio1, No* polinomio2);
No* multiplicaPolinomio(No *l1,No *l2);
ResultadoDivisao* criaResultadoDivisao();
ResultadoDivisao* dividirPolinomios(No* polinomio1, No* polinomio2);
/**DERIVADA**/
No* simplificaPolinomio(No *l);

int verificaString(char* str);
float integralPolinomio(No* polinomio, int intervaloSuperior, int intervaloInferior);
No* integral(No* polinomio);

float resultadoPolinomio(No *l,float v);
float compostoPolinomio(No *l1,No *l2,float v);
float n_compostoPolinomio(float v);

/** Toda vez que fizer uma operacao nova, inserir o string do usuario ou resultado da operação
(ex: Resultado=3x^2+2x) na lista LOG, no fim, quando usario requsitar o arquivo log, tudo da
lista eh escrito e printado do arquivo. **/
char *transformaPolinomio(No* polinomio);
NoLOG* criaListaLOG(); /**Inicializar no main **/
NoLOG* InsereInicioLOG(NoLOG* l, char* info); /** Funcao nova **/
void escreveLOG(FILE *log, NoLOG *lista); /** Funcao nova **/
void imprimeLOG(FILE *log); /** Funcao nova **/

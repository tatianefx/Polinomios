#include "Polinomios.h"

/*A função cria uma lista vazia*/
No* criaLista()
{
    return NULL;
}

/* inserção no início: retorna a lista atualizada */
No* insereInicio (No* l, float coef, int exp)
{
    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){ printf("Erro."); exit(1);}

    novo->coef = coef;
    novo->exp = exp;

    return novo;
}

/* inserção no fim: retorna a lista atualizada */
No* insereFim (No* l, float coef, int exp)
{
    No *novo, *p;
    p = l;

    if(p == NULL)
    {
        l = insereInicio(l, coef, exp);
        return l;
    }

    novo = (No*) malloc(sizeof(No));
    if(novo==NULL){ printf("Erro."); exit(1);}

    while(p->proximo != NULL)                        /*Buscando o fim da lista*/
    {
        p = p->proximo;
    }

    p->proximo = novo;

    novo->coef = coef;
    novo->exp = exp;
    novo->proximo = NULL;

    return l;
}

/* função remove um no: o usuário entra com um
or do nó que será removido*/
No* removeNo (No* l, float coef)
{
    No *ant, *atual;
    ant = NULL;
    atual = l;

    while((atual != NULL) && (atual->coef != coef))
    {
        ant = atual;
        atual = atual->proximo;
    }

    if(atual == NULL) return l;
    if(ant == NULL)
    {
        l = atual->proximo;
    }
    else
    {
        ant->proximo = atual->proximo;
    }

    free(atual);

    return l;
}

/* função imprime: imprime valores dos elementos */
void imprimeLista (No* l)
{
    No* p;
    p = l;
    while(p != NULL)
    {
        printf("(%0.2f, %d) ", p->coef, p->exp);
        p = p->proximo;
    }
}

/*A função desaloca a lista*/
void destroiLista(No* l)
{
    No *atual, *prox;
    atual = l;

    while(atual != NULL)
    {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
}

/*A função pega os coeficientes e expoentes de uma string(na forma de polinomio) e coloca em uma lista*/
No* transformaString(char* str, No* lista)
{
    char strNumero[MAX];
    char strExp[MAX];
    char sinal = '+';

    float coef = 0;
    int expo = 0;

    while(strlen(str))                                      /*roda enquanto a string str não é vazia*/
    {
        if (str[0] == '+' || str[0] == '-')                 /*quarda o sinal e o apaga da string str*/
        {
            sinal = str[0];
            apagarParteString(str, 1);
        }

        copiaParteNumerica(str, &strNumero);                /*copia o coeficiente para a string strNumero*/

        if(strlen(strNumero) == 0) coef = 1;                /*verifica se possui coeficiente*/

        apagarParteString(str, strlen(strNumero));          /*apaga a string strNumero do começo de str*/

        if(str[0] == 'x')                                   /*verifica se o primeiro caractere de str é 'x'*/
        {
            apagarParteString(str,1);                       /*se for, apaga o caractere 'x' do começo da string str*/

            if(str[0] == '^')                               /*verifica se x possui expoente*/
            {
                apagarParteString(str, 1);                  /*se possuir apaga caractere '^' do começo da string str*/

                copiaParteNumerica(str, &strExp);           /*copia o expoente para a string strExp*/

                apagarParteString(str, strlen(strExp));     /*apaga a string strExp do começo da string str*/
            }
            else expo = 1;                                  /*se não possuir expoente determina que o expoente é igual a 1*/
        }
        else expo = 0;                                      /*se o primeiro caractere da string str não for 'x'
                                                            o expoente é igual a zero*/

        if(strlen(strNumero)) coef = atof(strNumero);       /*verifica se as strings não são nulas*/
        if(strlen(strExp)) expo = atoi(strExp);
        if(sinal == '-') coef = coef*(-1);                  /*se o sinal for negativo
                                                            o coeficiente é multiplicado por -1*/

        lista = insereFim(lista, coef, expo);               /*insere nó na lista com coeficiente e expoente obtidos*/

                                                            /*apaga todas as variaveis auxiliares*/
        coef = 0;
        expo = 0;
        sinal = '+';

        apagarParteString(strNumero, strlen(strNumero));
        apagarParteString(strExp, strlen(strExp));
    }

    return lista;                                           /*retorna a lista*/
}

/*A função apaga quantidade de caracteres apartir do começo*/
void apagarParteString(char* str, int qnt)
{
    int tam, i;

    tam = strlen(str) - qnt;

    for (i = 0; str[tam] != '\0'; i++)
    {
        str[i] = str[qnt];
        qnt++;
    }

    str[tam] = '\0';
}

/*A função copia a parte numerica do começo da primeira string para a segunda string*/
void copiaParteNumerica(char* str1, char* str2)
{
    int i;

    for (i = 0; (str1[i] >= '0' && str1[i] <= '9' || str1[i] == '.') ; i++)
    {
        str2[i] = str1[i];
    }

    str2[i] = '\0';
}

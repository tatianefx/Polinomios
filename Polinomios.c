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

/* função insereOrdenado: insere elemento em ordem e retorna a lista atualizada*/
No* insereOrdenado (No* l, float coef, int exp)
{
    No* novo;
    No* ant = NULL;                         /* ponteiro para elemento anterior à posição de inserção*/
    No* post = l;                           /* ponteiro para elemento posterior à posição de inserção*/

    /* procura posição de inserção */
    while (post != NULL && post->exp > exp)
    {
        ant = post;
        post = post->proximo;
    }

    /* cria novo elemento */
    novo = (No*) malloc(sizeof(No));
    if(novo==NULL)
    {
        printf("Erro.");                                 /*testa se houve alocacao*/
        exit(1);
    }
    novo->coef = coef;
    novo->exp = exp;

    /* encadeia elemento na posição correta */
    if (ant == NULL)                                    /* testa se elemento será no início*/
    {
        novo->proximo = l;
        l = novo;
    }
    else /* insere elemento no meio ou fim da lista */
    {
        novo->proximo = ant->proximo;
        ant->proximo = novo;
    }
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
    char strNumero[MAX] = "\0";
    char strExp[MAX] = "\0";
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

        copiaParteNumerica(str, strNumero);                /*copia o coeficiente para a string strNumero*/

        if(strlen(strNumero) == 0) coef = 1;                /*verifica se possui coeficiente*/
        else apagarParteString(str, strlen(strNumero));          /*apaga a string strNumero do começo de str*/

        if(str[0] == 'x')                                   /*verifica se o primeiro caractere de str é 'x'*/
        {
            apagarParteString(str,1);                       /*se for, apaga o caractere 'x' do começo da string str*/

            if(str[0] == '^')                               /*verifica se x possui expoente*/
            {
                apagarParteString(str, 1);                  /*se possuir apaga caractere '^' do começo da string str*/

                copiaParteNumerica(str, strExp);           /*copia o expoente para a string strExp*/

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

        lista = insereOrdenado(lista, coef, expo);          /*insere nó na lista com coeficiente e expoente obtidos*/

                                                            /*apaga todas as variaveis auxiliares*/
        coef = 0;
        expo = 0;
        sinal = '+';

        strcpy(strNumero,"\0");
        strcpy(strExp,"\0");
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

    for (i = 0; ( (str1[i] >= '0' && str1[i] <= '9') || str1[i] == '.') ; i++)
    {
        str2[i] = str1[i];
    }

    str2[i] = '\0';
}


/***Não terminei ainda***/
No* subtrairPolinomios(No* polinomio1, No* polinomio2)
{
    No *polinomioResultante, *p1, *p2;

    polinomioResultante = criaLista();

    p1 = polinomio1;
    p2 = polinomio2;

    if(polinomio1 == NULL && polinomio2 == NULL) return NULL;                   /*testa se os polinomios nao sao nulos*/

    if(polinomio1 != NULL && polinomio2 == NULL) return polinomio1;             /*se polinomio2 é nulo, retorna polinomio 1*/

    if(polinomio1 == NULL && polinomio2 != NULL) return polinomio2;              /*se polinomio1 é nulo, retorna polinomio 2*/

    while(p1 != NULL || p2 != NULL)
    {
        while( (p1->exp != p2->exp) && (p1 != NULL && p2 != NULL) )             /*percorre as listas procurando expoentes iguais*/
        {
            if(p1->exp > p2->exp) p1 = p1->proximo;                             /*se o expoente de p1 é maior do que o de p2,
                                                                                p1 aponta para o proximo*/
            else p2 = p2->proximo;                                              /*se nao p2 aponta para o proximo*/
        }

                                                                                /*se todos os expoentes sao diferentes,
                                                                                insere a p1 e insere p2 com todos os coeficientes
                                                                                multiplicados por -1*/
        if(p1 == NULL || p2 == NULL)
        {
            p1 = polinomio1;
            p2 = polinomio2;

            while(p1 != NULL || p2 != NULL)
            {
                if(p1 != NULL)
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, p1->coef, p1->exp);
                    p1 = p1->proximo;
                }

                if(p2 != NULL)
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, (p2->coef * (-1)), p2->exp);
                    p2 = p2->proximo;
                }
            }
        }

        /***Não terminei ainda***/
    }

    return polinomioResultante;
}


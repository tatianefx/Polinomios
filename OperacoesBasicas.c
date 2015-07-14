#include "Polinomios.h"

/*A função cria um resultado de divisão vazio*/
ResultadoDivisao* criaResultadoDivisao()
{
    ResultadoDivisao* novo = (ResultadoDivisao*) malloc(sizeof(ResultadoDivisao));

    novo->quociente = NULL;
    novo->resto = NULL;

    return novo;
}

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
No* removeNo (No* l, No *endereco)
{
    No *ant, *atual;
    ant = NULL;
    atual = l;

    while((atual != NULL) && (atual!=endereco))
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

    if(p == NULL) printf("Lista Vazia!");

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

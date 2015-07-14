#include "Polinomios.h"

/*A função pega os coeficientes e expoentes de uma string(na forma de polinomio) e coloca em uma lista*/
No* transformaString(char* str)
{
    No* polinomio = criaLista();

    char strCoef[MAX] = "\0";
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

        copiaParteNumerica(str, strCoef);                   /*copia o coeficiente para a string strNumero*/

        if(strlen(strCoef) == 0) coef = 1;                  /*verifica se possui coeficiente*/
        else apagarParteString(str, strlen(strCoef));       /*apaga a string strNumero do começo de str*/

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
        if(strlen(strCoef)) coef = atof(strCoef);           /*verifica se as strings não são nulas*/
        if(strlen(strExp)) expo = atoi(strExp);
        if(sinal == '-') coef = coef*(-1);                  /*se o sinal for negativo
                                                            o coeficiente é multiplicado por -1*/

        polinomio = insereOrdenado(polinomio, coef, expo);          /*insere nó na lista com coeficiente e expoente obtidos*/

                                                            /*apaga todas as variaveis auxiliares*/
        coef = 0;
        expo = 0;
        sinal = '+';

        strcpy(strCoef,"\0");
        strcpy(strExp,"\0");
    }

    return polinomio;                                           /*retorna a lista*/
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

/* A função insere os dois polinômios a serem somados e
depois simplifica-os já que a inserção é ordenada*/
No *somaPolinomio(No *l1,No *l2)
{

    No *l3,*p1,*p2;

    l3=criaLista();
    p1=l1;
    p2=l2;

    while(p1!=NULL || p2!=NULL)
    {
        if(p1!=NULL)
        {
            l3=insereOrdenado(l3,p1->coef,p1->exp);
            p1=p1->proximo;
        }
        if(p2!=NULL)
        {
            l3=insereOrdenado(l3,p2->coef,p2->exp);
            p2=p2->proximo;
        }
    }

    l3=simplificaPolinomio(l3);

    return l3;
}

No* subtrairPolinomios(No* polinomio1, No* polinomio2)
{
    No *polinomioResultante, *p1, *p2;

    polinomioResultante = criaLista();

    p1 = polinomio1;
    p2 = polinomio2;

    if(polinomio1 == NULL && polinomio2 == NULL) return NULL;       /*testa se os polinomios nao sao nulos*/

    while(p1 != NULL || p2 != NULL)                                 /*percorres as listas ate o fim das duas*/
    {
        if(p1 != NULL && p2 != NULL)                         /*Se p1 e p2 forem diferentes de nulo*/
        {

            if(p1->exp == p2->exp)                          /*Se possuirem expoentes iguais*/
            {
                if((p1->coef - p2->coef) != 0)              /*se o coeficiente p1 menos o
                                                            coeficiente de p2 não for igual a zero,
                                                            insere na lista resultante*/
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, (p1->coef - p2->coef), p1->exp);
                    p1 = p1->proximo;
                    p2 = p2->proximo;
                }
                else                                       /*se não aponta para o proximo*/
                {
                    p1 = p1->proximo;
                    p2 = p2->proximo;
                }
            }
            else                                          /*se os coeficientes forem diferentes*/
            {
                if(p1->exp > p2->exp)                     /*se o expoente de p1 é maior do que o de p2,
                                                          insere p1 e aponta para o proximo*/
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, p1->coef, p1->exp);
                    p1 = p1->proximo;
                }
                else                                      /*se nao insere p2 e aponta para o proximo*/
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, (p2->coef* (-1)), p2->exp);
                    p2 = p2->proximo;
                }
            }
        }
        else                                              /*Se uma das listas for nula*/
        {
            if(p1 != NULL)                                /*Se p1 não for o nulo insere na
                                                          lista resultante e aponta para o proximo*/
            {
                polinomioResultante = insereOrdenado(polinomioResultante, p1->coef, p1->exp);
                p1 = p1->proximo;
            }
            if(p2 != NULL)                                 /*Se p2 não for o nulo insere na
                                                           lista resultante e aponta para o proximo*/
            {
                polinomioResultante = insereOrdenado(polinomioResultante, -p2->coef, p2->exp);
                p2 = p2->proximo;
            }
        }
    }

    return polinomioResultante;
}

/* A função abaixo multiplica dois polinômios*/
No* multiplicaPolinomio(No *l1,No *l2)
{
    No* l3,*p1,*p2;
    l3=criaLista();

    p1=l1;
    p2=l2;

    while(p1!=NULL)
    {

        while(p2!=NULL)
        {

            if(p1->exp!=0 && p2->exp==0) /*Se o expoente do segundo polinômio for zero*/
                l3 = insereOrdenado(l3,p1->coef*p2->coef,p1->exp);

            else if(p1->exp==0 && p2->exp!=0) /*Se o expoente do primeiro polinômio for zero*/
                l3 = insereOrdenado(l3,p1->coef*p2->coef,p2->exp);
            else
                l3 = insereOrdenado(l3,p1->coef*p2->coef,p1->exp+p2->exp); /*Se os dois expoentes forem diferentes de 0*/
            p2=p2->proximo;
        }
        p2=l2;
        p1=p1->proximo;
    }

    l3=simplificaPolinomio(l3);

    /**Gravar no arquivo**/

    return l3;
}

ResultadoDivisao* dividirPolinomios(No* polinomio1, No* polinomio2)
{
    ResultadoDivisao* resultado;
    No *pAux, *p;

    float coef;
    int expo;

    resultado = criaResultadoDivisao();                 /*recebe resultado da divisao */
    pAux = criaLista();

    if(polinomio1->exp < polinomio2->exp)               /*se o expoente do primeiro no
                                                        do polinomio1 é menor doque o
                                                        expoente do primeiro no do polinomio2 */
    {
        p = polinomio1;

        while(p != NULL)                                /*insere o polinomio1 no resto
                                                        do ressultado, e o quociente eh zero*/
        {
            resultado->resto = insereOrdenado(resultado->resto, p->coef, p->exp);
            p = p->proximo;
        }

        return resultado;
    }

    p = polinomio1;

    do
    {
        coef = (p->coef / polinomio2->coef);                        /*divide os coeficientes*/
        expo = (p->exp - polinomio2->exp);                          /*subtrai os expoentes*/

        resultado->quociente = insereOrdenado(resultado->quociente, coef, expo);     /*quarda o resultado no quociente*/

        pAux = insereInicio(pAux, coef, expo);                      /*guarda o coeficiente e o expoente calculados*/

        pAux = multiplicaPolinomio(pAux, polinomio2);               /*guarda o resuldado da multiplicação dos
                                                                    valores do ultimo no do quoeficiente pelo polinomio2*/

        resultado->resto = subtrairPolinomios(p, pAux);             /*recebe o resuldado da subtracao de p po pAux*/

        pAux = removeNo(pAux, pAux);                                /*remove o unico no de pAux*/

        p = resultado->resto;                                       /*p aponta pro resto*/
    }
    while( (resultado->resto != NULL) && (resultado->resto->exp >= polinomio2->exp) );  /*faz isso enquanto o resto
                                                                                        for diferente zero e o expoente
                                                                                        do primeiro no do resto for
                                                                                        maior/igual ao expoente do
                                                                                        primeiro no do polinomio2 */

    return resultado;                                               /*retorna o resuldado*/
}

/* Nesta função compara-se nó a nó para verificar se é possível a simplificação
então soma-se os coeficientes e elimina-se um nó */
No* simplificaPolinomio(No *l)
{

    No *atual,*post;

    atual=l;
    post=l->proximo;

    while(post!=NULL)
    {

        if(atual->exp==post->exp)
        {
            post->coef+=atual->coef;
            l=removeNo(l,atual);
        }
        atual=post;
        post=post->proximo;
    }

    return l;
}

/* A função lê um valor real e calcula o resultado do polinômio */
float resultadoPolinomio(No *l,float v)
{

    float res=0;
    No *p;

    p=l;

    while(p!=NULL)
    {

        res+=p->coef*pow(v,p->exp);
        p=p->proximo;
    }

    /*TODO
    ESCREVER RESULTADO NO ARQUIVO!*/
    return res;
}


/* A composição calcula o valor inserido em um polinômio e
pega esse resultado calculando no proximo polinomio  */
float compostoPolinomio(No *l1,No *l2,float v){

    No *q=l1;
    No *p=l2;

    float res;

    res=resultadoPolinomio(q,v);
    res=resultadoPolinomio(p,res);

    return res;
}

/* Na enésima composição o valor de x é recebido,
depois polinômio é lido e calcula-se o valor para cada polinômio inserido
sempre usando o ultimo resultado calculado*/
float n_compostoPolinomio(float v){

    char stringPolinomio[MAX];

    while(1){
        No *l=criaLista();
        printf("Entre com i-esimo polinomio.(Tecla S p/ sair),\n");
        fflush(stdin);
        gets(stringPolinomio);
        if(stringPolinomio[0]=='S' || stringPolinomio[0]=='s')
            break;
        l=transformaString(stringPolinomio);
        v=resultadoPolinomio(l,v);
        destroiLista(l);
    }
    return v;
}

int verificaString(char* str)
{
    int i, contemX = 0;
    char numero;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'x') contemX = 1;

        if( !(str[i] >= '0' && str[i] <= '9') && str[i] != 'x' && str[i] != '^' && str[i] != '+' && str[i] != '-' && str[i] != '.')
        {
            return 0;
        }

        if(str[i] == 'x' && (str[i+1] != '^' && str[i+1] != '+' && str[i+1] != '-' && str[i+1] != '\0' ) )
        {
            return 0;
        }

        if(str[i] == '^' &&  !(str[i+1] >= '0' && str[i+1] <='9'))
        {
            return 0;
        }
    }

    if(contemX) return 1;
    else return 0;
}

/*Funcao integra um polinomio em um intervalo*/
float integralPolinomio(No* polinomio, int intervaloSuperior, int intervaloInferior)
{
    No* polinomioResultante;
    float resultado;

    polinomioResultante = criaLista();

    polinomioResultante = integral(polinomio);          /*integra o polinomio
                                                        e depois calcula o resultado*/

    resultado = resultadoPolinomio(polinomioResultante, intervaloSuperior) - resultadoPolinomio(polinomioResultante, intervaloInferior);

    return resultado;
}

/*Integra o polinomio e o polinomio resultante é guardado em outra lista. Obs: não considera a constante gerada apos a integral*/
No* integral(No* polinomio)
{
    No* polinomioResultante, *p;

    polinomioResultante = criaLista();

    p = polinomio;

    while(p != NULL)             /*enquanto p não aponta para nulo insere novo nó no polinomioResultante*/
    {
                                /*o coeficiente de cada nó do polinomio é o coeficiente que p aponta dividido pelo expoente somado com 1
                                e o expoente é o expoente que p aponta somado com 1 */
        polinomioResultante = insereOrdenado(polinomioResultante, (p->coef/(p->exp + 1)), (p->exp + 1));
        p = p->proximo;
    }

    return polinomioResultante;
}

No* calculaDerivada(No* polinomio){

    No *polinomioResultante, *p1;

    polinomioResultante = criaLista();

    p1 = polinomio;

    if(polinomio == NULL) return NULL;       /*testa se o polinomio nao eh nulo*/

    while(p1 != NULL)
    {
        if(p1->exp >= 1)    /* Faz a derivada de para o elevado >= 1, pois derivada de uma constante é zero */
        {
            polinomioResultante = insereOrdenado(polinomioResultante, (p1->coef * p1->exp), p1->exp - 1);
        }

        p1 = p1->proximo;
    }

    return polinomioResultante;
}


/** Funcao transforma uma lista de um polinomio em string **/
/*
char *transformaPolinomio(No* polinomio)
{
    No* p = polinomio;
    char stringPolinomio[MAX], aux[10];

    while(p != NULL)
    {
        if(p->coef == 1 && p->coef != 0) strcat(stringPolinomio, "x");
        else
        {
            ftoa(p->coef, aux);
            strcat(stringPolinomio, aux);
            strcat(stringPolinomio, "x");
        }

        if(p->exp > 1)
        {
            strcat(stringPolinomio, "^");
            itoa(p->exp, aux, 10);
            strcat(stringPolinomio, aux);
        }

        p = p->proximo;
    }

    return stringPolinomio;
}
*/

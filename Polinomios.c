#include "Polinomios.h"

/*A função pega os coeficientes e expoentes de uma string(na forma de polinomio) e coloca em uma lista*/
No* transformaString(char* str, No* lista)
{
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

        copiaParteNumerica(str, strCoef);                /*copia o coeficiente para a string strNumero*/

        if(strlen(strCoef) == 0) coef = 1;                /*verifica se possui coeficiente*/
        else apagarParteString(str, strlen(strCoef));          /*apaga a string strNumero do começo de str*/

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

        lista = insereOrdenado(lista, coef, expo);          /*insere nó na lista com coeficiente e expoente obtidos*/

                                                            /*apaga todas as variaveis auxiliares*/
        coef = 0;
        expo = 0;
        sinal = '+';

        strcpy(strCoef,"\0");
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

No* subtrairPolinomios(No* polinomio1, No* polinomio2)
{
    No *polinomioResultante, *p1, *p2;

    polinomioResultante = criaLista();

    p1 = polinomio1;
    p2 = polinomio2;

    if(polinomio1 == NULL && polinomio2 == NULL) return NULL;                   /*testa se os polinomios nao sao nulos*/

    if(polinomio1 != NULL && polinomio2 == NULL) return polinomio1;              /*se polinomio2 é nulo, retorna polinomio 1*/

    if(polinomio1 == NULL && polinomio2 != NULL) return polinomio2;              /*se polinomio1 é nulo, retorna polinomio 2*/

    while(p1 != NULL || p2 != NULL)                                              /*percorres as listas ate o fim das duas*/
    {
        if(p1 != NULL && p2 != NULL)                                             /*Se p1 e p2 forem diferentes de nulo*/
        {

            if(p1->exp == p2->exp)                                               /*Se possuirem expoentes iguais*/
            {
                if((p1->coef - p2->coef) != 0)                                  /*se o coeficiente p1 menos o
                                                                                coeficiente de p2 não for igual a zero,
                                                                                insere na lista resultante*/
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, (p1->coef - p2->coef), p1->exp);
                    p1 = p1->proximo;
                    p2 = p2->proximo;
                }
                else                                                            /*se não aponta para o proximo*/
                {
                    p1 = p1->proximo;
                    p2 = p2->proximo;
                }
            }
            else                                                                /*se os coeficientes forem diferentes*/
            {
                if(p1->exp > p2->exp)                                           /*se o expoente de p1 é maior do que o de p2,
                                                                                insere p1 e aponta para o proximo*/
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, p1->coef, p1->exp);
                    p1 = p1->proximo;
                }
                else                                                            /*se nao insere p2 e aponta para o proximo*/
                {
                    polinomioResultante = insereOrdenado(polinomioResultante, (p2->coef* (-1)), p2->exp);
                    p2 = p2->proximo;
                }
            }
        }
        else                                                                    /*Se uma das listas for nula*/
        {
            if(p1 != NULL)                                                      /*Se p1 não for o nulo insere na
                                                                                lista resultante e aponta para o proximo*/
            {
                polinomioResultante = insereOrdenado(polinomioResultante, p1->coef, p1->exp);
                p1 = p1->proximo;
            }
            if(p2 != NULL)                                                      /*Se p2 não for o nulo insere na
                                                                                lista resultante e aponta para o proximo*/
            {
                polinomioResultante = insereOrdenado(polinomioResultante, -p1->coef, p1->exp);
                p1 = p1->proximo;
            }
        }
    }

    return polinomioResultante;
}

void multiplicaPolinomio(No *l1,No *l2)
{

    No* l3,*p1,*p2;
    l3=criaLista();

    p1=l1;
    p2=l2;

    while(p1!=NULL){

        while(p2!=NULL){

            if(p1->exp!=0 && p2->exp==0)
                l3 = insereOrdenado(l3,p1->coef*p2->coef,p1->exp);

            else if(p1->exp==0 && p2->exp!=0)
                l3 = insereOrdenado(l3,p1->coef*p2->coef,p2->exp);

            else
                l3 = insereOrdenado(l3,p1->coef*p2->coef,p1->exp*p2->exp);

            p2=p2->proximo;
        }
        p2=l2;
        p1=p1->proximo;
    }
    imprimeLista(l3);
    /**Falta simplificar e gravar no arquivo**/
}

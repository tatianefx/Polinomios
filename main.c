#include "Polinomios.h"

int main(void)
{
    char stringPolinomio[MAX];
    FILE *arquivo, *log; /* log = registro das entradas do usuario */
    int n, aux = 1;
    No* lista = criaLista();

    printf("\n Digite 1 para ler o polinomio de um arquivo e 2 para ler o polinomio do teclado: \n");
    scanf("%d", &n);
    if(n != 1 || n != 2)  /* Verifica se o usuario digitou um numero invalido */
    {
        while(n != 1 || n != 2)
        {
            printf("\nOpcao invalida, digite 1 para ler o polinomio de um arquivo e 2 para ler o polinomio do teclado: \n");
            scanf("%d", &n);
        }
    }

    switch(n)  /*Verifica se por onde o usario quer enviar o polinomio*/
    {
    case 1:/* Le o(s) polinomio(s) de um arquivo */
        if((arquivo = fopen("arquivo.txt", "r+")) == NULL)  /* Abre arquivo */
        {
            printf("Erro na abertura do arquivo");
            exit(1);
        }
        else
        {
            while((fgets(stringPolinomio, sizeof(stringPolinomio), arquivo))!=NULL)  /*Le cada linha do arquivo e insere no stringPolinomio*/
            {
                lista = transformaString(stringPolinomio, lista);
            }
        }
        break;
    case 2:/* Le o(s) polinomio(s) do teclado */
        do /* Continua lendo os polinomios ate o usuario optar por parar */
        {
            printf("Entre com o polinomio:\n");
            setbuf(stdin, NULL);
            scanf("%s", &stringPolinomio);
            setbuf(stdin, NULL);
            lista = transformaString(stringPolinomio, lista);
            printf("\nDeseja adicionar mais polinomios? Digite 0 para sair, 1 para continuar a adicionar.\n");
            scanf("%d", &aux);
        }
        while(aux != 0);
        break;
    }

    printf("\nDigite 1 para somar dois polinomios.");
    printf("\nDigite 2 para subtrair dois polinomios.");
    printf("\nDigite 3 para multiplicar dois polinomios.");
    printf("\nDigite 4 para dividir dois polinomios.");
    printf("\nDigite 5 para calcular a derivada de um polinomio.");
    printf("\nDigite 6 para simplificar um polinomio.");
    printf("\nDigite 7 para calcular o polinomio dado um valor para x.");
    printf("\nDigite 8 para calcular um polinomio composto Q(P(x)) dado x.");
    printf("\nDigite 9 para calcular um polinomio composto por quantos polinomios desejar.");
    printf("\nDigite 0 para sair.\n");

    scanf("%d", &n);

    while(n != 0)
    {
        switch(n) /* Switch-case das operacoes polinomiais */
        {
        case 1:/* Soma */
            /*Chamada de funcao */
            break;
        case 2:/* Subtracao */
            /*Chamada de funcao */
            break;
        case 3:/* Multiplicacao */
            /*Chamada de funcao */
            break;
        case 4: /* Divisao */
            /*Chamada de funcao */
            break;
        case 5:/* Derivada */
            /*Chamada de funcao */
            break;
        case 6:/* Simplificar */
            /*Chamada de funcao */
            break;
        case 7:/* Calcular P(x) a partir de x */
            /*Chamada de funcao */
            break;
        case 8:/* Q(P(x)) */
            /*Chamada de funcao */
            break;
        case 9: /* Polinomios compostos */
            /*Chamada de funcao */
            break;
        }

        printf("\nProxima operacao: ");
        scanf("%d", &n);
    }

    fclose(arquivo);

    return 0;
}

#include "Polinomios.h"

int main(void)
{
    char stringPolinomio[MAX];
    FILE *arquivo, *log; /* log = registro das entradas do usuario */
    NoLOG *historico;
    int n, aux = 1, valor, valor2;
    float res;

    No *polinomio1, *polinomio2, *polinomio3, *lista;

    lista = criaLista();
    historico = criaListaLOG();

    polinomio1 = criaLista();
    polinomio2 = criaLista();
    polinomio3 = criaLista();

    arquivo = fopen("arquivo.txt", "a+");
    if(arquivo == NULL)  /* Abre arquivo */
    {
            printf("Erro na abertura do arquivo");
            exit(1);
    }

    do /* Verifica se o usuario digitou um numero invalido */
    {
        printf("\nDigite uma opcao:");
        printf("\n1- Ler o polinomio de um arquivo.");
        printf("\n2- Ler o polinomio do teclado:\n");
        scanf("%d", &n);

    }
    while(n != 1 && n != 2);

    switch(n)  /*Verifica se por onde o usario quer enviar o polinomio*/
    {
    case 1:/* Le o(s) polinomio(s) de um arquivo */
        while (!feof(arquivo))
        {
            fgets(stringPolinomio, MAX, arquivo);
            printf("\n%s", stringPolinomio);
            lista = transformaString(stringPolinomio);
            imprimeLista(lista);
        }

        break;

    case 2:/* Le o(s) polinomio(s) do teclado */
        do /* Continua lendo os polinomios ate o usuario optar por parar */
        {
            printf("Entre com o polinomio:\n");
            setbuf(stdin, NULL);
            scanf("%s", &stringPolinomio);
            setbuf(stdin, NULL);

            fputs(stringPolinomio, arquivo);

            printf("\nDeseja adicionar mais polinomios?");
            printf("\nDigite uma opcao:");
            printf("\n1- Continuar a adicionar.");
            printf("\n0- Sair.\n");

            scanf("%d", &aux);
        }
        while(aux != 0);

        break;

    default:
        ;
    }

    do
    {

    printf("\n\nDigite uma opcao:");
    printf("\n1- Somar dois polinomios.");
    printf("\n2- Subtrair dois polinomios.");
    printf("\n3- Multiplicar dois polinomios.");
    printf("\n4- Dividir dois polinomios.");
    printf("\n5- Calcular a derivada de um polinomio.");
    printf("\n6- Simplificar um polinomio.");
    printf("\n7- Calcular o polinomio dado um valor para x.");
    printf("\n8- Calcular um polinomio composto Q(P(x)) dado x.");
    printf("\n9- Calcular um polinomio composto por quantos polinomios desejar.");
    printf("\n10- Integral definida.");
    printf("\n11- Integral indefinida.");
    printf("\n0- Sair.\n\n");

    scanf("%d", &n);

        switch(n) /* Switch-case das operacoes polinomiais */
        {
        case 1:/* Soma */
            do
            {
                printf("\nEntre com o polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            do
            {
                printf("\nEntre com o outro polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio2 = transformaString(stringPolinomio);

            polinomio3 = somaPolinomio(polinomio1, polinomio2);

            printf("Resultado = ");
            imprimeLista(polinomio3);

            break;

        case 2:/* Subtracao */
            do
            {
                printf("\nEntre com o polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            do
            {
                printf("\nEntre com o outro polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio2 = transformaString(stringPolinomio);

            polinomio3 = subtrairPolinomios(polinomio1, polinomio2);

            printf("Resultado = ");
            imprimeLista(polinomio3);

            break;
        case 3:/* Multiplicacao */
            do
            {
                printf("\nEntre com o polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            do
            {
                printf("\nEntre com o outro polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio2 = transformaString(stringPolinomio);

            polinomio3 = multiplicaPolinomio(polinomio1, polinomio2);

            printf("Resultado = ");
            imprimeLista(polinomio3);

            break;

        case 4: /* Divisao */
            do
            {
                printf("\nEntre com o polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            do
            {
                printf("\nEntre com o outro polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio2 = transformaString(stringPolinomio);

            polinomio3 = dividirPolinomios(polinomio1, polinomio2);

            printf("Resultado = ");
            imprimeLista(polinomio3);

            break;

        case 5:/* Derivada */
            do
            {
                printf("\nEntre com o outro polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            polinomio2 = calculaDerivada(polinomio1);

            printf("Resultado = ");
            imprimeLista(polinomio2);

            break;
        case 6:/* Simplificar */
            do
            {
                printf("\nEntre com o polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            polinomio2 = simplificaPolinomio(polinomio1);

            printf("Resultado = ");
            imprimeLista(polinomio2);

            break;

        case 7:/* Calcular P(x) a partir de x */
            do
            {
                printf("\nEntre com o polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            printf("\nEntre com o valor:\n");
            scanf("%f", &valor);

            res = resultadoPolinomio(polinomio1, valor);

            printf("Resultado = %f", valor);

            break;

        case 8:/* Q(P(x)) */
            do
            {
                printf("\nEntre com o polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            do
            {
                printf("\nEntre com o polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio2 = transformaString(stringPolinomio);

            printf("\nEntre com o valor:\n");
            scanf("%f", &valor);

            res = compostoPolinomio(polinomio1, polinomio2, valor);

            printf("Resultado = %f", valor);

            break;

        case 9: /* Polinomios compostos */

            printf("\nEntre com o valor:\n");
            scanf("%f", &valor);

            res = n_compostoPolinomio(valor);

            printf("Resultado = %f", valor);

            break;

        case 10: /* Integral definida */
            do
            {
                printf("\nEntre com o polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            printf("\nEntre com o valor do intervalo superior:\n");
            scanf("%f", &valor);

            printf("\nEntre com o valor do intervalo inferior:\n");
            scanf("%f", &valor2);

            res = integralPolinomio(polinomio1, valor, valor2);

            printf("Resultado = %f", res);

            break;

        case 11: /*Integral indefinida*/
            do
            {
                printf("\nEntre com o polinomio:\n");
                setbuf(stdin, NULL);
                scanf("%s", &stringPolinomio);
                setbuf(stdin, NULL);
                if(!verificaString(stringPolinomio)) printf("\nPolinomio invalido, digite novamente:\n");
            }
            while(!verificaString(stringPolinomio));

            polinomio1 = transformaString(stringPolinomio);

            polinomio2 = integral(polinomio1);

            printf("Resultado = ");
            imprimeLista(polinomio2);

            break;

        default:;
        }

    } while(n != 0);

    fclose(arquivo);

    return 0;
}

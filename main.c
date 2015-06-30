 #include "Polinomios.h"

int main(void)
{
    No *p1, *p2, *p3;
    char strP1[MAX], strP2[MAX];

    p1 = criaLista();
    p2 = criaLista();
    p3 = criaLista();

    printf("Entre com o polinomio:\n");
    setbuf(stdin, NULL);
    scanf("%s", &strP1);
    setbuf(stdin, NULL);

    printf("\nEntre com outro polinomio:\n");
    setbuf(stdin, NULL);
    scanf("%s", &strP2);
    setbuf(stdin, NULL);

    p1 = transformaString(strP1, p1);
    p2 = transformaString(strP2, p2);

    p3 = subtrairPolinomios(p1,p2);

    printf("\nLista do polinomio:\n");
    imprimeLista(p3);

     printf("\nLista do polinomio:\n");
    imprimeLista(p1);

     printf("\nLista do polinomio:\n");
    imprimeLista(p2);
    return 0;
}

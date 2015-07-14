#include "Polinomios.h"

int main(void)
{
   char stringPolinomio[MAX];

    printf("Entre com o polinomio:\n");
    setbuf(stdin, NULL);
    scanf("%s", &stringPolinomio);
    setbuf(stdin, NULL);

    if(verificaString(stringPolinomio))  printf("\nÉ polinomio\n");
    else printf("\nNÃO É\n");


    return 0;
}

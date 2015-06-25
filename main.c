#include "Polinomios.h"

int main()
{
    char stringPolinomio[MAX];

    No* lista = criaLista();

    printf("Entre com o polinomio:\n");
    setbuf(stdin, NULL);
    scanf("%s", &stringPolinomio);
    setbuf(stdin, NULL);

    lista = transformaString(stringPolinomio, lista);

    printf("\nLista do polinomio:\n");
    imprimeLista(lista);

    return 0;

}

#include "Polinomios.h"

NoLOG* criaListaLOG(){ /* Cria lista do LOG */
    return NULL;
}

/* Insere no inicio da lista LOG as operações e resultados do usuário */
NoLOG* InsereInicioLOG (NoLOG* l, char* info){
    NoLOG* novo = (NoLOG*) malloc(sizeof(NoLOG));
    if(novo == NULL){ printf("Erro."); exit(1);}

    novo->info = info;
    novo->proximo = l;

    return novo;
}

FILE* escreveLOG(FILE *log, NoLOG* l){ /** Funcao recebe uma lista L e insere ela no arquivo **/
    log = fopen("log.txt", "r+");

    if(log == NULL){ printf("Erro, nao foi possivel abrir o arquivo\n");}

	else{
	    while(l != NULL){ /** Enquanto a lista nao chegar no fim, insere a string NoLOG por cada char* na lista no arquivo, linha a linha **/
                fprintf(log, "%s \n", l->info); /** Insere na linha **/
                l = l->proximo;
            }
	}
	fclose(log);
    return log;
}

void imprimeLOG(FILE *log){ /** Funcao que imprime o LOG **/
    char s[20];
    log = fopen("log.txt", "r");

    if(log == NULL){ printf("Erro, nao foi possivel abrir o arquivo\n");}

    else{
            while(fscanf(log,"%s", &s) != EOF){ /* Printa linha a linha */
                    printf("%s \n", s);
            }
        }

    fclose(log);
}

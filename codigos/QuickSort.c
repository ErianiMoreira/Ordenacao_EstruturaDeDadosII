#include <stdio.h>
#include <stdlib.h>
#define N 5

void quicksort (int *dados, int esq, int dir);
void particao (int *dados, int esq, int dir, int *i, int *j);

int main(int argc, char** argv) {
    int vetor[N], i;
    
    for(i=0; i<N; i++){
        printf("Informe o valor: \n");
        scanf("%d", &vetor[i]);
    }
    quicksort(vetor,0,4);

    for(i=0; i<N; i++){
        printf("Valor:%d \n", vetor[i]);
    }

    return (EXIT_SUCCESS);
}

void particao (int *dados, int esq, int dir, int *i, int *j){
    int pivo, aux;
    
    *i = esq;
    *j = dir;
    pivo = dados[(esq+dir) /2];
    
    while(*i <= *j){
        while(dados[*i] < pivo && *i < dir){
            (*i)++;
        }
        while(dados[*j] > pivo && *j < esq){
            (*j)--;
        }
        if(*i <= *j){
            aux = dados[*i];
            dados[*i] = dados[*j];
            dados[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }
}

void quicksort (int *dados, int esq, int dir){
    int i, j;
    particao(dados, esq, dir, &i,&j);
    
    if( i < dir){
        quicksort(dados, i, dir);
    }
    if(j > esq){
        quicksort(dados, esq, j);
    }
}


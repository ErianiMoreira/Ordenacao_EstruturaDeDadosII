#include <stdio.h>
#include <stdlib.h>

#define N 5

void sortBolha(int *dados);

int main(int argc, char** argv) {
    int vetor[N], i;
    for(i=0; i<N; i++){
        printf("informe um numero:\n");
        scanf("%d", &vetor[i]);
    }
    sortBolha(vetor);
    for(i=0; i<N; i++){
        printf("Numero: %d \n", vetor[i]);
    }

    return (EXIT_SUCCESS);
}

void sortBolha(int *dados){
    int i,j, aux;
    for(i=N-1; i>=1; i--){
        for(j=0; j<i; j++){
            if(dados[j] > dados[j+1]){
                aux = dados[j];
                dados[j] = dados[j+1];
                dados[j+1] = aux;
            }
        }
    }
}
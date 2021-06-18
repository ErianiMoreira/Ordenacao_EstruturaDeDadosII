#include <stdio.h>
#include <stdlib.h>
#define verdadeiro 0
#define falso -1

void BolhaParada(int *dados);

int main(int argc, char** argv) {
    int N;
    N=5;
    int vetor[N], i;
    for(i=0; i<N; i++){
        printf("informe um numero:\n");
        scanf("%d", &vetor[i]);
    }
    BolhaParada(vetor);
    for(i=0; i<N; i++){
        printf("Numero: %d \n", vetor[i]);
    }
    return (EXIT_SUCCESS);
}

void BolhaParada(int *dados){
    int mudou, indice,j,N, aux; 
    N=5;
    mudou = verdadeiro;
    indice = N;
    while (mudou == verdadeiro){
        j = 1;
        mudou = falso;
        while(j<N){
            if(dados[j-1]> dados[j]){
                aux = dados[j-1];
                dados[j-1]= dados[j];
                dados[j]= aux;
                mudou = verdadeiro;
            }
            indice = j;
            j = j+1;
        }
        N = indice;
    }     
}
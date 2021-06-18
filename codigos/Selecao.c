#include <stdio.h>
#include <stdlib.h>
#define N 5

void selecao (int *dados);

int main(int argc, char** argv) {
    int vetor[N], i;
    
    for(i=0; i<N; i++){
        printf("Informe o valor: \n");
        scanf("%d", &vetor[i]);
    }
    selecao(vetor);

    for(i=0; i<N; i++){
        printf("Valor:%d \n", vetor[i]);
    }

    return (EXIT_SUCCESS);
}

void selecao (int *dados){
    int i,j,menor,aux;
    
    for(i=0; i < (N-1); i++){
        menor = i;
        for( j = (i+1); j < N; j++){
            if(dados[j] < dados[menor]){
                menor = j;
            }
        }
        if( i != menor){
            aux = dados[menor];
            dados[menor] =dados[i];
            dados[i] = aux;
        }
    } 
}


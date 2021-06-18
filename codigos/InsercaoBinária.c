#include <stdio.h>
#include <stdlib.h>
#define N 5

void binaria(int *dados);

int main(int argc, char** argv) {
    int vetor[N], i;
    
    for(i=0; i<N; i++){
        printf("Informe o valor: \n");
        scanf("%d", &vetor[i]);
    }
    
    binaria(vetor);
    
    for(i=0; i<N; i++){
        printf("Valor: %d \n", vetor[i]);
    }
    

    return (EXIT_SUCCESS);
}

void binaria(int *dados) {
    int i,j, aux, esq, dir, meio;
    
    for(i=1; i<N ;i++){
        aux = dados[i];
        esq = 0;
        dir= i;
        while(esq<dir){
            meio = (esq + dir) /2;
            if(dados[meio] <= aux)
                esq = meio+1;
            else
                dir = meio;
        }
        for(j=i; j>esq; j--){
            dados[j] = dados[j-1];
        }
        dados[dir] = aux;
    }
}

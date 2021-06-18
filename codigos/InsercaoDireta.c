#include <stdio.h>
#include <stdlib.h>

#define N 5


void direta( int *dados);

int main(int argc, char** argv) {
    int vetor[N], i;
    
    for(i=0; i<N; i++){
        printf("Infome o valor: \n");
        scanf("%d", &vetor[i]);
    }
    
    direta(vetor);
    
    for(i=0; i<N; i++){
        printf(" valor: %d \n", vetor[i]);
    }

    return (EXIT_SUCCESS);
}


void direta( int *dados){
    int i,j,aux;
    
    for(i=1; i<N; i++){
        aux = dados[i];
        j= i-1;
        while(j>=0 && aux < dados[j]){
            dados[j+1] = dados[j];
            j--;
        }
        if (j != (i-1))
            dados[j+1] = aux;        
    }
}


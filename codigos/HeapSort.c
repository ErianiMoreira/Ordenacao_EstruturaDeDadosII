#include <stdio.h>
#include <stdlib.h>
#define N 6

void heapSort (int *dados, int n);
void criaHeap (int *v, int i, int f);

int main(int argc, char** argv) {
    int vetor[N], i;
    
    for(i=0; i<N; i++){
        printf("Informe o valor: \n");
        scanf("%d", &vetor[i]);
    }
    heapSort(vetor,N);

    for(i=0; i<N; i++){
        printf("\nValor:%d \n", vetor[i]);
    }

    return (EXIT_SUCCESS);
}

void criaHeap (int *v, int i, int f){
    int aux = v[i];
    int j = i * 2 + 1;
    
    while( j<= f){
       if(j < f){
           if(v[j] < v[j+1]){
               j = j+1;
           }
       }
       if(aux < v[j]){
           v[i] = v[j];
           i = j;
           j = 2*i+1;
       }else{
           j = f+1;
       }
    }
    v[i] = aux;
}   

void heapSort (int *dados, int n){
    int i, aux;
    
    for(i =((n-1)/2); i>=0; i--){
        criaHeap(dados, i, n-1);
        i= i-1;
    }
    for( i =(n-1); i>=1; i--){
        aux = dados[0];
        dados[0] = dados[i];
        dados[i] = aux;
        criaHeap(dados, 0, i-1);        
    }

}


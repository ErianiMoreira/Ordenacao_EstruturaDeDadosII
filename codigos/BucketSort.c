#include <stdio.h>
#include <stdlib.h>
#define N 8
#define TAM 5

struct balde{
   int qtd;
   int valores[TAM];
};

void bucketSort (int *dados, int n);
void heapSort (int *dados, int n);
void criaHeap (int *v, int i, int f);

int main(int argc, char** argv) {
    int vetor[N], i;
    
    for(i=0; i<N; i++){
        printf("Informe o valor: \n");
        scanf("%d", &vetor[i]);
    }
    bucketSort(vetor,N);

    for(i=0; i<N; i++){
        printf("\nValor:%d \n", vetor[i]);
    }

    return (EXIT_SUCCESS);
}  

void bucketSort (int *dados, int n){
    int i, j, maior, menor,numBaldes, pos;
    struct balde *bd;
    
    maior = menor = dados[0];
    
    for(i=1; i<=n; i++ ){
        if(dados[i]> maior)
            maior= dados[i];
        if(dados[i]<menor)
            menor = dados[i];
    }
    numBaldes = ((maior - menor)/TAM+1);
    bd = (struct balde *) malloc(numBaldes * sizeof(struct balde));
    
    for(i=0; i< numBaldes; i++){
        bd[i].qtd = 0;
    }
    for(i=0; i< n; i++){
        pos = (dados[i] - menor)/TAM;
        bd[pos].valores[bd[pos].qtd] = dados[i];
        bd[pos].qtd++;
    }
            
    pos = 0;
    
    for(i=0; i< numBaldes; i++){
        heapSort(bd[i].valores, bd[i].qtd);
        for( j =0; j<bd[i].qtd; j++){
            dados[pos] = bd[i].valores[j];
            pos++;
        }
    }
    free(bd);
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
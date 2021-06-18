#include <stdio.h>
#include <stdlib.h>
#define N 6

void Mergesort (int *dados, int inicio, int final);
void intercalar (int *valores, int inicio, int fim, int meio);

int main(int argc, char** argv) {
    int vetor[N], i;
    
    for(i=0; i<N; i++){
        printf("Informe o valor: \n");
        scanf("%d", &vetor[i]);
    }
    Mergesort(vetor,0,N-1);

    for(i=0; i<N; i++){
        printf("\nValor:%d \n", vetor[i]);
    }

    return (EXIT_SUCCESS);
}

void intercalar (int *valores, int inicio, int fim, int meio){         
    int *aux, i,j, k;
    i = inicio;
    j = meio+1;
    k = 0;
    aux = (int *) malloc((fim-inicio+1)*sizeof(int));
    while ((i< meio+1)||(j<fim+1)){
        if( (i== meio+1) ||((valores[j]< valores[i]) && ( j != fim+1))){
            aux[k] = valores[j];
            j = j+1;
            k = k+1;
        }
        else{
            aux[k] = valores[i];
            i=i+1;
            k=k+1;
        }
    }
    for(i = inicio;i<=fim; i++){
        valores[i] = aux[i-inicio];
    }
    free(aux);
}


void Mergesort (int *dados, int inicio, int fim){
    int meio;
    
    if(inicio< fim){
       meio = (inicio+fim)/2;
       Mergesort( dados, inicio, meio);
       Mergesort( dados,meio+1, fim);
       intercalar(dados, inicio,fim, meio);
    }
}


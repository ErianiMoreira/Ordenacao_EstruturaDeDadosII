#include <stdio.h>
#include <stdlib.h>
#define N 5

void diminuirIncremento (int *dados);

int main(int argc, char** argv) {
    int vetor[N], i;
    
    for(i=0; i<N; i++){
        printf("Informe o valor: \n");
        scanf("%d", &vetor[i]);
    }
    diminuirIncremento(vetor);

    for(i=0; i<N; i++){
        printf("Valor:%d \n", vetor[i]);
    }

    return (EXIT_SUCCESS);
}

void diminuirIncremento (int *dados){
    int i,j,h,aux;
    h = 1;
    while(h < N){
        h = 3*h +1;
    }
    while( h>1){
        h/=3;
        for(i=h; i<N; i++){
            aux = dados[i];
            j = i-h;
            while( j >= 0 && aux< dados[j]){
                dados[j+h] = dados[j];
                j -=h;
            }
             dados[j+h] = aux;
        }
    }
}


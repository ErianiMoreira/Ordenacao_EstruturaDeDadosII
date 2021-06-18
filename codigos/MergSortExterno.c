#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 100
typedef struct Arquivo{
    FILE *f;
    int pos,MAX, *buffer;
}arquivo;

void mergeSortExterno(char *nome);
int criaArquivoOrdenados(char *nome);
void criaArquivoTeste(char *nome);
void salvaArquivo(char *nome,int *V, int tam, int mudaLinhaFinal);
void merge(char *nome,int numArqs, int k);
int procuraMenor(arquivo *arq,int numArqs, int k, int * menor);
void preencheBuffer(arquivo *arq,int k);
int compara(const void *a, const void *b);


int main(){
    criaArquivoTeste("dados.txt");
    mergeSortExterno("dados.txt");
    printf("\n\t Arquivos criados com sucesso!!\n");
    return 0;
}
void criaArquivoTeste(char *nome){
    int i;
    FILE *f=fopen(nome, "w");
    srand(time(NULL));
    for(i=1;i<1000;i++){
        fprintf(f,"%d\n",rand());
    }
    fprintf(f,"%d",rand());
    fclose(f);
}
void mergeSortExterno(char *nome){
    char novo[20];
    int numArqs=criaArquivoOrdenados(nome);
    int i,k=  n/(numArqs+1);
    //k=  x /(numArqs+1);
    remove(nome);
    merge(nome,numArqs,k);
    for(i=0;i<numArqs;i++){
        sprintf(novo,"Tempo%d.txt",i+1);
        remove(novo);
    }
}

int criaArquivoOrdenados(char *nome){
    int V[n],cont=0,total=0;
    char novo[20];
    FILE *f= fopen(nome,"r");
    while(!feof(f)){
        fscanf(f,"%d",&V[total]);
        total++;
        if(total==n){
            cont++;
            sprintf(novo,"Temp%d.txt",cont);
            qsort(V,total,sizeof(int),compara);
            salvaArquivo(novo,V,total,0);
            total=0;
        }
    }
    if(total>0){
            cont++;
            sprintf(novo,"Temp%d.txt",cont);
            qsort(V,total,sizeof(int),compara);
            salvaArquivo(novo,V,total,0);
    }
    fclose(f);
    return cont;

}
void salvaArquivo(char *nome,int *V, int tam, int mudaLinhaFinal){
    int i;
    FILE *f= fopen(nome,"a");
    for(i=0;i<tam-1;i++){
        fprintf(f,"%d\n",V[i]);
    }
    if(mudaLinhaFinal==0){
        fprintf(f,"%d",V[tam-1]);
    }else{
        fprintf(f,"%d\n",V[tam-1]);
    }
    fclose(f);
}

void merge(char *nome,int numArqs, int k){
    char novo[20];
    int i;
    int *buffer=(int*)malloc(k*sizeof(int));
    arquivo *arq;
    arq=(arquivo*)malloc(numArqs* sizeof(arquivo));
    for(i=0;i<numArqs; i++){
        sprintf(novo,"Temp%d.txt",i+1);
        arq[i].f=fopen(novo,"r");
        arq[i].MAX=0;
        arq[i].pos=0;
        arq[i].buffer=(int *)malloc(k*sizeof(int));
        preencheBuffer(&arq[i],k);
    }
    int menor, qtdBuffer=0;
    while(procuraMenor(arq, numArqs,k, &menor)==1){
        buffer[qtdBuffer]=menor;
        qtdBuffer++;
        if(qtdBuffer==k){
            salvaArquivo(nome,buffer,k,1);
            qtdBuffer=0;
        }
    }
    if(qtdBuffer!=0){
        salvaArquivo(nome,buffer,qtdBuffer,1);
    }
    for(i=0;i<numArqs;i++){
        free(arq[i].buffer);
    }
    free(arq);
    free(buffer);
}
int procuraMenor(arquivo *arq,int numArqs, int k, int * menor){
    int i ,idx=-1;
    for(i=0;i<numArqs;i++){
        if(arq[i].pos<arq[i].MAX){
            if(idx== -1){
                idx=i;
            }else{
                if(arq[i].buffer[arq[i].pos]< arq[idx].buffer[arq[idx].pos]){
                    idx=i;
                }
            }
        }
    }
    if(idx!=-1){
        *menor=arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if(arq[idx].pos==arq[idx].MAX){
            preencheBuffer(&arq[idx],k);
        }
        return 1;
    }else{
        return 0;
    }
}

void preencheBuffer(arquivo *arq,int k){
    int i;
    if( arq->f==NULL){
        return;
    }
    arq->pos=0;
    arq->MAX=0;
    for(i=0;i<k;i++){
        if(!feof(arq->f)){
            fscanf(arq->f,"%d",&arq->buffer[arq->MAX]);
            arq->MAX++;
        }else{
            fclose(arq->f);
            arq->f=NULL;
            break;
        }
    }

}
int compara(const void *a, const void *b){
    if(*(int*)a == *(int*)b)
        return 0;
    else
        if(*(int*)a < *(int*)b)
            return -1;
        else
            return 1;

}

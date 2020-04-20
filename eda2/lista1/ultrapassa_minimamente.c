#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *head,*atual;

void inserir(int e){
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->dado = e;
    atual = head->prox;
    head->prox = nova;
    nova->prox = atual;
}


int main(){

    int *v,x,n=0,limite,j=0,sum=0;

    v = malloc(sizeof(int));
    head = malloc(sizeof(celula));
    head->prox=NULL;

    scanf(" %d",&x);
    for(x;x!=0;scanf(" %d",&x)){
        v[n]=x;
        n++;
        v = realloc(v,(n+1)*sizeof(int));
    }

    scanf(" %d",&limite);

    for(int i=0;i<n;i++){
        sum+=v[i];
        if(sum>limite){
            sum=0;
            inserir(v[i]);
            j++;
        }
    }
    head = head->prox;
    for(int i=0;i<j;i++){
        printf("%d\n",head->dado);
        head = head->prox;
    }

    return 0;
}
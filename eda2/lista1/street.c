#include<stdio.h>
#include<stdlib.h>

typedef struct pilha{
    int *dados;
    int N, topo;
}pilha;

void inicializa(pilha *p){
    p->N = 1;
    p->topo = 0;
    p->dados = malloc(sizeof(int));
}

void empilha(pilha *p,int e){
    if(p->topo==p->N){
        p->dados = realloc(p->dados,2*p->N*sizeof(int));
        p->N*=2;
    }
    p->dados[p->topo]=e;
    p->topo++;
}

int desempilha(pilha *p){
    p->topo--;
    return p->dados[p->topo];
}

void destroi(pilha *p){
    free(p->dados);
}

int main(){

    pilha main, aux;
    int n,x=1,j=1,test=0;



    
    while(n!=0){
        j=1;
        inicializa(&main);
        inicializa(&aux);
        scanf(" %d",&n);
        if(n==0)return 0;
        test=0;
        for(int i=0;i<n;i++){
            scanf(" %d",&x);
            if(x==0)break;

            if(x==j){
                empilha(&main,x);
                j++;
            }
            else empilha(&aux,x);
            while(aux.dados[aux.topo-1]==j&&aux.topo>0){
                empilha(&main,desempilha(&aux));
                j++;
            }
        }
        
        while(aux.topo!=0){
            empilha(&main,desempilha(&aux));
        }
        for(int i=0;i<main.topo-1;i++){
            if(main.dados[i]>main.dados[i+1]){
                printf("no\n");
                test=1;
                break;
            }
        }
        if(test==0)printf("yes\n");
        destroi(&main);
        destroi(&aux);
    }

    return 0;
}
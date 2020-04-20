#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct celula{
    char cidade[26];
    struct celula *prox;
}celula;

celula *head, *atual;

void inserir(char *c){
    celula *nova;
    nova = malloc(sizeof(celula));
    for(int i=0;i<=strlen(c);i++)
        nova->cidade[i] = c[i];
    nova->prox = NULL;
    atual->prox = nova;
    atual = atual->prox;
}


int main(){

celula *aux;
int n=0,t=-1;
char city[26];
head = malloc(sizeof(celula));
atual = head;

while(scanf(" %s",city)==1){
    n++;
    inserir(city);
}
printf("%s\n",head->prox->cidade);

for(int i=0;i<n-1;i++){
    head = head->prox;
    if((head->prox->cidade[0]+32)==head->cidade[strlen(head->cidade)-1]){
        aux = head->prox;
        head->prox = aux->prox;
        atual->prox = aux;
        aux->prox = NULL;
        atual = atual->prox;
    }
    printf("%s\n",head->prox->cidade);
}

    return 0;
}
#include<stdio.h>
#include<stdlib.h>

typedef struct no{
  int coluna;
  int valor;
  struct no *prox;
}no;

typedef struct matriz{
  int linhas;
  int colunas;
  no **valores;
}matriz;

void inicializa(int linhas, int colunas, matriz *m){
  m->linhas = linhas;
  m->colunas = colunas;
  m->valores = malloc(linhas*sizeof(no *));

  for(int i=0; i<linhas; i++){
    m->valores[i] = malloc(sizeof(no));
    m->valores[i]->prox = NULL;
  }
}

void inserir(int linha, int coluna, int valor, matriz *m){
  no *anterior = m->valores[linha];
  no *atual = anterior->prox;

  while(atual!=NULL&&atual->coluna<coluna){
    anterior = atual;
    atual = atual->prox;
  }
  if(atual==NULL||atual->coluna>coluna){
    if(valor!=0){
      no *novo = malloc(sizeof(no));
      novo->coluna = coluna;
      novo->valor = valor;
      novo->prox = atual;
      anterior->prox = novo;
    }
  }
  else{
    if(valor!=0)atual->valor = valor;
    else{
      anterior->prox = atual->prox;
      free(atual);
    }
  }
}

int main(){

  matriz *mat;
  mat = malloc(sizeof(matriz));

  int m,n,*v;
  int l,c,e,i,temp;

  scanf("%d %d",&m,&n);

  inicializa(m,n,mat);

  v = malloc(n*sizeof(int));

  for(i=0;i<n;i++)
    scanf("%d",&v[i]);

  do{
    scanf("%d",&l);
    if(l==EOF)break;
    scanf("%d %d",&c,&e);
    inserir(l,c,e,mat);
  }while(l!=EOF);

  for(i=0;i<n;i++){
    temp = 0;
    no *atual;
    atual = mat->valores[i]->prox;
    while(atual!=NULL){
      temp+=v[atual->coluna]*atual->valor;
      atual = atual->prox;
    }
    printf("%d\n",temp);
  }



    return 0;
}

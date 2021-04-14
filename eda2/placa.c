#include <stdio.h>
#include <stdlib.h>

#define key(a) (a)
#define less(x,y) (key(x)<key(y))
#define exch(x,y){ int t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

int *pq;
int N;

#define MAX 102

void PQinit(int maxN){
  pq = malloc(sizeof(int) * (maxN + 1));
  N = 0;
}

int PQempty(){
  return N == 0;
}

void fixUp(int *v, int k){
  while(k > 1 && less(v[k/2], v[k])){
    exch(v[k], v[k/2]);
    k = k/2;
  }
}

void fixDown(int *v, int k, int N) {
  int j;
  while(2*k <= N){
    j = 2*k;
    if(j < N && less(v[j], v[j+1]))
      j++;
    
    if(!less(v[k], v[j]))
      break;

    exch(v[k], v[j]);
    k = j;
  }
}

void PQinsert(int novo){
  pq[++N] = novo;
  fixUp(pq, N);
}

void PQworkaroundMax(int x){
  pq[1] = x;
  fixDown(pq, 1, N);
}

int PQdelMax() {
  exch(pq[1], pq[N]);
  fixDown(pq, 1, N-1);
  return pq[N--];
}

int PQespiaMax(){
  return pq[1];
}

int separa(int *v, int l, int r){
    int c = v[r];
    int j=l, k;
    for(k=l;k<r;k++){
        if(less(v[k],c)){
            exch(v[k],v[j]);
            j++;
        }
    }
    exch(v[k],v[j]);
    return j;
}

void quicksort(int *v, int l, int r){
    int j;
    if(r<=l)return;
    j=separa(v,l,r);
    quicksort(v,l,j-1);
    quicksort(v,j+1,r);
}

int main() {
  int op, t, i=0,x, *aux,j;
  PQinit(MAX);
  while(scanf("%d", &op)==1){
    if(op==1){
      scanf("%d",&x);
      if(i==101){
        if(x<PQespiaMax()){
          PQworkaroundMax(x);
        }
      }
      else{
        PQinsert(x);
        i++;
      }
    }
    else{
      scanf("%d",&t);
      aux = malloc(i*sizeof(int));
      for(j=1;j<=i;j++){
        aux[j-1] = pq[j];
      }
      quicksort(aux,0,i-1);
      for(j=0;j<t-1;j++)printf("%d ",aux[j]);
      printf("%d",aux[j]);
      printf("\n");
    }
  }
}
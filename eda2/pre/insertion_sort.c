#include<stdio.h>
#include<stdlib.h>

void troca(int *x,int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

void insertion_sort(int *v,int l, int r){
    
    int atual,j;

    for(int i=l+1;i<r;i++){
        j = i-1;
        atual = v[i];
        while(atual<v[j]&&j>=0){
            troca(&v[j],&v[j+1]);
            j--;
        }
    }
}

int main(){
    int v[1000],n=0;

    for(;scanf("%d",&v[n])!=EOF;n++);
    
    insertion_sort(v,0,n);

    for(int i=0;i<n;i++){
        if(i==0)
            printf("%d",v[i]);
        else   
            printf(" %d",v[i]);
    }
    printf("\n");

    return 0;
}
#include<stdio.h>

#define key(a) (a)
#define less(x,y) (key(x)<key(y))
#define exch(x,y){ int t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

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

int main(){

    int v[100000],n;

    for(n=0;scanf("%d",&v[n])==1;n++);

    quicksort(v,0,n-1);

    printf("%d",v[0]);
    for(int i=1;i<n;i++)printf(" %d",v[i]);
    printf("\n");

    return 0;
}
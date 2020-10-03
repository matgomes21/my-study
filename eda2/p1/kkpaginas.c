#include<stdio.h>
#include<stdlib.h>

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

void quickselect(int *v, int l, int r, int k){
    int i;
    if(r<=l)return;
    i = separa(v,l,r);
    if(i>k)quickselect(v,l,i-1,k);
    if(i<k)quickselect(v,i+1,r,k);
}

void quicksort(int *v, int l, int r){
    int j;

    if(r<=l)return;
    
    cmpexch(v[(l+r)/2],v[r]);
    cmpexch(v[l],v[(l+r)/2]);
    cmpexch(v[r],v[(l+r)/2]);

    j=separa(v,l,r);
    quicksort(v,l,j-1);
    quicksort(v,j+1,r);
}

int main(){
    int n, p, x, *id, k;

    scanf("%d%d%d",&n,&p,&x);
    id = malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)scanf("%d",&id[i]);

    k = p*x;
    quickselect(id,0,n-1,k);
    quicksort(id, k, n-1);

    for(int i=0;i<x&&k<n;i++)
        printf("%d\n",id[k++]);

    return 0;
}
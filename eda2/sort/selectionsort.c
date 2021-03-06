#include<stdio.h>
#include<stdlib.h>

#define key(a) (a)
#define less(x,y) (key(x)<key(y))
#define exch(x,y){ int t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

void selectionsort(int *v, int l, int r){
    if(l==r)return;
    int min=l;
    for(int j=l+1;j<=r;j++){
        if(less(v[j],v[min]))
            min=j;
    }
    exch(v[min],v[l]);
    selectionsort(v,l+1,r);
}

int main() {
    int n,*v;
    scanf("%d",&n);
    v = malloc(n*sizeof(int));

    for(int i=0;i<n;i++)scanf("%d",&v[i]);

    selectionsort(v,0,n-1);

    printf("%d",v[0]);
    for(int i=1;i<n;i++){
        printf(" %d",v[i]);
    }
    printf("\n");

    return 0;
}
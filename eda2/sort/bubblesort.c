#include<stdio.h>
#include<stdlib.h>

#define key(a) (a)
#define less(x,y) (key(x)<key(y))
#define exch(x,y){ int t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

void bubblesort(int *v, int l, int r){
    for(int i=l;i<r;i++)
        for(int j=l; j<r;j++)
            cmpexch(v[j],v[j+1]);
}

int main(){
    int *v,n;

    scanf("%d",&n);

    v = malloc(n*sizeof(int));

    for(int i=0;i<n;i++)scanf("%d",&v[i]);

    bubblesort(v,0,n-1);

    printf("%d",v[0]);

    for(int i=1;i<n;i++){
        printf(" %d",v[i]);
    }
    printf("\n");

    return 0;
}
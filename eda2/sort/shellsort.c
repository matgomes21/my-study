#include<stdio.h>
#include<stdlib.h>

#define key(a) (a)
#define less(x,y) (key(x)<key(y))
#define exch(x,y){ int t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

void insertionsortH(int *v, int l, int r, int h){
    for(int i=l+h;i<=r;i++){
        int j=i, tmp=v[i];
        while(j>=l+h&&less(tmp,v[j-h])){
            v[j] = v[j-h];
            j-=h;
        }
        v[j]=tmp;
    }
}

void shellsort(int *v, int l, int r){
    int h;
    for(h=1;h<=(r-l)/9;h=3*h+1);
    for(;h>0;h/=3)
        insertionsortH(v,l,r,h);
}

int main(){
    int *v, n;

    scanf("%d",&n);

    v = malloc(n*sizeof(int));

    for(int i=0;i<n;i++)scanf("%d",&v[i]);

    shellsort(v,0,n-1);

    printf("%d",v[0]);

    for(int i=1;i<n;i++)printf(" %d",v[i]);
    printf("\n");

    return 0;
}
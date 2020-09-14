#include<stdio.h>
#include<stdlib.h>

#define key(a) (a)
#define less(x,y) (key(x)<key(y))
#define exch(x,y){ int t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

void insertionSort(int *v, int l, int r){
    int k=1;
    for(int i=r;i>l;i--)cmpexch(v[i-1],v[i]);
    printf("%d",v[0]);
    for(int i=l+2;i<=r;i++){
        int j=i;
        int temp=v[j];
        while(less(temp,v[j-1])){
            v[j]=v[j-1];
            j--;
        }
        v[j]=temp;
    }
}

int main(){
    int *v,n;

    scanf("%d",&n);

    v = malloc(n*sizeof(int));

    for(int i=0;i<n;i++)scanf("%d",&v[i]);

    insertionSort(v,0,n-1);

    for(int i=1;i<n;i++){
        printf(" %d",v[i]);
    }
    printf("\n");

    return 0;
}
#include<stdio.h>

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
    int v[50000],i;

    for(i=0;scanf("%d",&v[i])==1;i++);

    insertionSort(v,0,i-1);

    for(int j=1;j<i;j++){
        printf(" %d",v[j]);
    }
    printf("\n");

    return 0;
}
#include<stdio.h>
#include<stdlib.h>

#define key(a) (a.count)
#define less(x,y) (key(x)<key(y))
#define exch(x,y){ Incident t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

typedef struct incident{
    int ascii;
    int count;
}Incident;

Incident *hash;

void insertionSort(Incident *v, int l, int r){
    int k=1;
    for(int i=r;i>l;i--)cmpexch(v[i-1],v[i]);
    for(int i=l+2;i<=r;i++){
        int j=i;
        Incident temp=v[j];
        while(less(temp,v[j-1])){
            v[j]=v[j-1];
            j--;
        }
        v[j]=temp;
    }
}

int main(){
    char string[1001];

    while(scanf(" %s",string)==1){
        hash=malloc(95*sizeof(Incident));
        for(int i=0;i<95;i++){
            hash[i].count=0;
            hash[i].ascii=i+33;
        }

        for(int i=0;string[i]!='\0';i++){
            hash[string[i]-33].count++;
        }

        insertionSort(hash,0,94);
        
        for(int i=0;i<95;i++){
            if(hash[i].count>0)
                printf("%d %d\n",hash[i].ascii,hash[i].count);
        }

        printf("\n");
        free(hash);
    }

    return 0;
}
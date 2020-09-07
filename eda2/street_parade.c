#include<stdio.h>
#include<stdlib.h>

int main() {

    int *v,n,sentinel,*aux;
    int j,true;

    scanf("%d",&n);

    while(n>0){
        true=1;sentinel=1;j=-1;
        v = malloc(n*sizeof(int));
        aux = malloc(n*sizeof(int));

        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
        }

        for(int i=0;i<n;i++){
            while(j>=0&&(aux[j]==sentinel)){
                sentinel++;
                j--;
            }

            if(v[i]==sentinel){
                sentinel++;
            }

            else{
                aux[++j]=v[i];
            }
        }

        for(;j>=0&&true;j--){
            if(aux[j]!=sentinel)true=0;
            else sentinel++;
        }

        if(true)printf("yes\n");
        else printf("no\n");

        free(v);
        free(aux);

        scanf("%d",&n);
    }

    return 0;
}
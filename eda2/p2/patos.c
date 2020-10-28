#include<stdio.h>
#include<stdlib.h>

int *hash;

int main() {
    int n,cor,maior;

    scanf("%d",&n);

    while(n>0){
        hash=calloc(n,sizeof(int));
        for(int i=0;i<n;i++){
            scanf("%d",&cor);
            hash[cor%n]++;
            if(i==0){
                maior=cor;
            }
            else{
                if(hash[cor%n]>hash[maior%n]){
                    maior=cor;
                }
            }
        }
        printf("%d\n",maior);
        free(hash);
        scanf("%d",&n);
    }

    return 0;
}
#include<stdio.h>

int main(){

    int n, soma=0,x;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        soma+=x;
    }

    printf("%d\n",soma);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>

typedef struct restaurant {
    int id;
    int stars;
} Restaurant;

int main() {
    int n,id,stars,day=0;
    Restaurant biggest;

    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++){
            scanf("%d%d",&id,&stars);
            if(i==0){
                biggest.id=id;
                biggest.stars=stars;
            }
            else{
                if(stars>biggest.stars){
                    biggest.id=id;
                    biggest.stars=stars;
                }
                else if(stars==biggest.stars){
                    if(id<biggest.id){
                        biggest.id=id;
                        biggest;stars=stars;
                    }
                }
            }
        }
        printf("Dia %d\n%d\n\n",++day,biggest.id);
    }

    return 0;
}
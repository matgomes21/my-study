#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t semaphore;

#define MAX 100000

int v1[MAX],v2[MAX];
int s1,s2,mod,x,c;

void increment(){
    sem_wait(&semaphore);
    c++;
    sem_post(&semaphore);
}

void *insertV1(void *a){
    for(int i=0;i<MAX;i++){
        v1[i] = rand_r(&s1);
    }
}
void *insertV2(void *a){
    for(int i=0;i<MAX;i++){
        v2[i] = rand_r(&s2);
    }
}

void *searchV1(void *a){
    for(int i=0;i<MAX;i++){
        if(v1[i]%mod==x){
            increment();
        }
    }
}
void *searchV2(void *a){
    for(int i=0;i<MAX;i++){
        if(v2[i]%mod==x){
            increment();
        }
    }
}

int main() {
    pthread_t tid1,tid2;
    sem_init(&semaphore,0,1);

    scanf("%d %d",&s1,&s2);

    pthread_create(&tid1, NULL, &insertV1, NULL);
    pthread_create(&tid2, NULL, &insertV2, NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    while(scanf("%d %d",&mod,&x)==2){
        c=0;
        pthread_create(&tid1, NULL, &searchV1, NULL);
        pthread_create(&tid2, NULL, &searchV2, NULL);

        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);

        printf("%d\n",c);
    }

    return 0;
}
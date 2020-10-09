#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Item{
    int key;
    char string[16];
}Item;

Item NULLItem = {-1, 'a'};

#define key(x) (x.key)
#define null(A) (key(ht[A])==key(NULLItem))

int N,M;
Item *ht;

void HTinit(int max){
    int i;
    N=0;M=2*max;
    ht = malloc(sizeof(Item)*M);
    for(i=0;i<M;i++)ht[i]=NULLItem;
}

int HTcount(){return N;}

int hashU(char *v){
    int sum=0,h;

    for(h=1;*v!='\0';v++){
        sum+=h*(*v);
        h++;
    }
    return (sum*19)%101;
}

void HTinsert(Item item){
    int i = key(item),j=1;
    while(!null(i)){
        if(j++==20||strcmp(ht[(i+j*j+23*j)%101].string, item.string))return;
        i=(i+1)%101;
    }
    item.key=i;
    ht[i] = item;
    N++;
}

// void HTinsert(Item item){
//     int i = key(item),j=1;
//     while(!null((i+j*j+23*j)%101)){
//         if(j++==20||strcmp(ht[(i+j*j+23*j)%101].string, item.string))return;
//     }
//     ht[(i+j*j+23*j)%101] = item;
//     N++;
// }

void HTdelete(Item item){
    int i = key(item),j=1;
    while(!null(i)){
        if(strcmp(item.string,ht[i].string)==0){
            key(ht[i]) = -1;
            N--;
            return;
        }
        i=(i+1)%101;
        if(j++==20)return;
    }
}

// void HTdelete(Item item){
//     int i = key(item),j=1;
//     while(!null((i+j*j+23*j)%101)){
//         if(strcmp(item.string,ht[(i+j*j+23*j)%101].string)==0){
//             ht[(i+j*j+23*j)%101] = NULLItem;
//             N--;
//             return;
//         }
//         if(j++==20)return;
//     }
// }

int main(){
    int t=1,n;
    char op[20];
    Item *new;

    scanf("%d%d",&t,&n);

    for(int test=0;test<t;test++){
        HTinit(101);

        for(int i=0;i<n;i++){
            scanf(" %s",op);
            new = malloc(sizeof(Item));
            new->key = hashU(op+4);
            strcpy(new->string,op+4);
            if(op[0]=='A'){
                HTinsert(*new);
            }
            else{
                HTdelete(*new);
            }
        }

        printf("%d\n",N);
        for(int i=0;i<M;i++){
            if(ht[i].key>=0)
                printf("%d:%s\n",ht[i].key,ht[i].string);
        }

        free(ht);
    }

    return 0;
}
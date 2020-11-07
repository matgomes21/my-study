#include <stdio.h>
#include <string.h>

int N;

void hashInit(char hash[101][15]){
    N=0;
    for(int i=0; i<101; i++)
        strcpy(hash[i], "NULL");
}

int hashIndex(char word[15]){
    int index=0;
    for(int i=0; word[i]!='\0'; i++)
        index+=word[i]*(i+1);
    
    return (index*19)%101;
}

int hashSearch(char hash[101][15], char word[15]){
    int trueIndex = hashIndex(word), newIndex;
    
    for(int j=0;j<20;j++){
        newIndex = (trueIndex+(j*j)+(23*j))%101;
        if(!strcmp(hash[newIndex], word))
            return newIndex;
    }
    return -1;
}

void hashAdd(char hash[101][15], char word[15]){
    if(hashSearch(hash, word)>=0)return;
    int index = hashIndex(word),newIndex;
    for(int j=0;j<20;j++){
        newIndex = (index+(j*j)+(23*j))%101;
        if(!strcmp(hash[newIndex],"NULL")){
            strcpy(hash[newIndex], word);
            N++;
            return;
        }
    }
}

void hashDelete(char hash[101][15], char word[15]){
    int index = hashSearch(hash, word);
    if(index==-1)return;
    strcpy(hash[index], "NULL");
    N--;


}

int main() {
    int t, n;
    char order[4], word[15];
    int codigo;

    scanf("%d", &t);

    for(int index=0; index<t; index++){
        scanf("%d",&n);
        char hash[101][15];

        hashInit(hash);

        for(int i=0;i<n;i++){
            scanf(" %c",&order[0]);
            for(int j=1; j<4; j++)
                scanf("%c",&order[j]);
            scanf("%s",word);

            if(order[0]=='A')
                hashAdd(hash, word);
            else if(order[0]=='D')
                hashDelete(hash, word);
        }

        printf("%d\n", N);

        for(int i=0; i<101; i++){
            if(strcmp(hash[i],"NULL"))
                printf("%d:%s\n",i,hash[i]);
        }
    }

    return 0;
}
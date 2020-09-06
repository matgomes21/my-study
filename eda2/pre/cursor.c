#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    int n,line,col;
    char **str, com;

    scanf("%d",&n);

    str = malloc(n*sizeof(char *));

    for(int i=0;i<n;i++){
        str[i] = malloc(1000*sizeof(char));
    }

    for(int i=0;i<n;i++){
        scanf(" %[^\n]", str[i]);
    }
    

    scanf("%d %d",&line,&col);
    line--;
    col--;
    while(scanf("%c",&com)==1){
        if(com=='j'){
            if(line+1<n)
                line++;
            if(strlen(str[line])==0)
                printf("%d %d\n",line+1,col+1);
            else if(col>=strlen(str[line])){
               printf("%d %ld %c\n",line+1, strlen(str[line]),str[line][strlen(str[line])-1]); 
            }
            else{
                printf("%d %d %c\n",line+1, col+1, str[line][col]);
            }
        }
        if(com=='k'){
            if(line-1>=0)
                line--;
            if(strlen(str[line])==0)
                printf("%d %d\n",line+1,col+1);
            else if(col>=strlen(str[line])){
               printf("%d %ld %c\n",line+1, strlen(str[line]),str[line][strlen(str[line])-1]); 
            }
            else{
                printf("%d %d %c\n",line+1, col+1, str[line][col]);
            }
        }
    }

    return 0;
}
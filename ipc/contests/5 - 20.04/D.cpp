#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

    char s[10000];

    while(cin>>s){
        for(int i=0;s[i]!='\0';i++)
            printf("%c",s[i]-7);
        cout<<endl;
    }

    return 0;
}
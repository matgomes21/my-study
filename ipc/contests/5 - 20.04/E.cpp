#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

    string s;
    int sum;

    while(getline(cin,s)){
        sum=1;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]==' '&&((s[i+1]>=65&&s[i+1]<=90)||(s[i+1]>=97&&s[i+1]<=122)))
                sum++;
        }
        cout<<sum<<endl;
    }

    return 0;
}
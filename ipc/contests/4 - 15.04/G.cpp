#include<iostream>

using namespace std;

void remove(char *s,int i){
    for(int j=i;s[j+1]!='\0';j++){
        s[j] = s[j+2];
    }
}


int main(){

    ios::sync_with_stdio(false);

    char s[100000];
    int c=0;

    cin>>s;

    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='1'){
            if(s[i+1]=='0'){
                remove(s,i);
                i=-1;
                c+=2;
            }
        }
        if(s[i]=='0'){
            if(s[i+1]=='1'){
                remove(s,i);
                i=-1;
                c+=2;
            }
        }
    }

    cout<<c<<endl;

    return 0;
}
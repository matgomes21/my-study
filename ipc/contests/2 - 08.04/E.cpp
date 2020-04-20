#include<iostream>

using namespace std;

int main(){

    int N,T;
    int c,t;
    int first=0;
    int menor;

    cin >>N>>T;

    while(N--){
        cin>>c>>t;
        if(first==0&&t<=T){
            first=1;
            menor = c;
        }
        else if(first==1){
            if(c<menor&&t<=T)menor=c;
        }
    }
    if(first)
    cout<<menor<<endl;
    else cout<<"TLE"<<endl;

    return 0;
}
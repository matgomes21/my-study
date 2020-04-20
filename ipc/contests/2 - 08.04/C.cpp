#include<iostream>

using namespace std;

int main(){

    int a,b;
    int flag=0;

    cin>>a>>b;

    if((a*b)%2!=0){
        flag=1;
    }
    if((a*b*2)%2!=0){
        flag=1;
    }
    if((a*b*3)%2!=0){
        flag=1;
    }
    if(flag==1)cout<<"Yes"<<endl;
    if(flag==0)cout<<"No"<<endl;


    return 0;
}
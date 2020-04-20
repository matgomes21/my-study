#include<iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int a,b,k;
    int d=0;

    cin>>a>>b>>k;

    while(k){
        d++;
        if(a%d==0&&b%d==0)k--;
    }
    cout<<d<<endl;

    return 0;
}
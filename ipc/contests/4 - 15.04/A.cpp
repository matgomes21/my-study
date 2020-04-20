#include<iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int a,b,c;

    cin>>a>>b>>c;

    if(b/a<c)cout<<b/a<<endl;
    else cout<<c<<endl;

    return 0;
}
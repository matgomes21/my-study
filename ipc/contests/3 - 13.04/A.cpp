#include<iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int x,y,coins=0;

    cin>>x>>y;

    if(x>y){
        coins+=x;
        x--;
    }
    else{
        coins+=y;
        y--;
    }

    if(x>y){
        coins+=x;
        x--;
    }
    else{
        coins+=y;
        y--;
    }

    cout<<coins<<endl;

    return 0;
}
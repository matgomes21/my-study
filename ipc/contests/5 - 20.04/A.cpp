#include<iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    unsigned int x,y;

    while(cin>>x>>y){
        cout<<y-x<<endl;
    }

    return 0;
}
#include<iostream>

using namespace std;

int main(){

    int k,cont=0;

    cin >> k;

    for(int i=2;i<=k;i+=2){
        for(int j=1;j<=k;j+=2){
            cont++;
        }
    }

    cout<<cont<<endl;

    return 0;
}
#include<iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int i,h,cont=1,limit;

    cin>>i;

    cin>>limit;
    i--;

    while(i--){
        cin>>h;
        if(h>=limit){
            cont++;
            if(h>limit)limit=h;
        }
    }

    cout<<cont<<endl;

    return 0;
}
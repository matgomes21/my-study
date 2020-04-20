#include<iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int n,l,x;
    int d=0,cont=1;;

    cin>>n>>x;

    while(n--){
        cin>>l;
        d += l;
        if(d<=x){
            cont++;
        }
        else break;
    }

    cout<<cont<<endl;

    return 0;
}
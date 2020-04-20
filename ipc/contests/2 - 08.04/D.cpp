#include<iostream>

using namespace std;

int main(){

    int n,pot=10;
    int sum=0;
    int aux;

    cin>>n;
    aux=n;
    while(n!=0){
        sum+=(n%pot)/(pot/10);
        n/=10;
    }

    if(aux%sum==0)cout << "Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
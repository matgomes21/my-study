#include<iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int n,f,x,y,z;
    int sum;

    cin>>n;

    while(n--){
        sum=0;
        cin>>f;
        while(f--){
            cin>>x>>y>>z;
            sum+=x*z;
        }
        cout<<sum<<endl;
    }

    return 0;
}
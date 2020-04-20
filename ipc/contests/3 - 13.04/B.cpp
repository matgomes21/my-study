#include<iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int a,b,c;

    cin>>a>>b>>c;

    if((a<=b&&b<=c)||(b<=a&&a<=c)){
        cout<<a+b<<endl;
    }
    else if((a<=c&&c<=b)||(c<=a&&a<=b)){
        cout<<a+c<<endl;
    }
    else{
        cout<<b+c<<endl;
    }

    return 0;
}
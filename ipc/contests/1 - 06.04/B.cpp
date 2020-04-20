#include<iostream>

using namespace std;

int main(){

    int a,b,maior;

    cin >> a >> b;

    maior = a+b;

    if(a*b>maior)maior = a*b;
    if(a-b>maior)maior = a-b;

    cout << maior << endl;

    return 0;
}
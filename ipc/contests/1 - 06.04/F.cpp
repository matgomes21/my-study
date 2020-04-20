#include<iostream>

using namespace std;

int main(){

    int n,d,e,mid,menor;
    int c1,c2;
    int suma,sumb,pot;

    cin >> n;

    mid = n/2;

    for(int i=1;i<=mid;i++){
        pot=10;
        c1=0;
        c2=0;
        suma=0;
        sumb=0;
        d = n-i;
        for(e=i;e/10!=0;e/=10)c1++;
        for(d=n-e;d/10!=0;d/=10)c2++;
        for(int j=1;j<=c1;j++){
            for(int k=1;k<j;k++){
                pot*=10;
            }
            suma+=(e%pot)/(pot/10);
        }
        pot=10;
        for(int j=1;j<=c2;j++){
            for(int k=1;k<j;k++){
                pot*=10;
            }
            sumb+=(d%pot)/(pot/10);
        }
        if(i==1){
            menor = suma+sumb;
        }
        else if(suma+sumb<menor)menor = suma+sumb;

    }

    cout << menor << endl;

    return 0;
}
#include<iostream>

using namespace std;

int main(){

    int a,b,c,k;

    cin >>a>>b>>c>>k;

    int maior,flag,sum;

    maior = a;
    flag =0;
    if(b>maior){
        maior=b;
        flag=1;}
    if(c>maior){
        maior=c;
        flag=2;}
    
    for(int i=0;i<k;i++){
        maior*=2;
    }


    if(flag==0){
        sum = b+c+maior;
    }
    if(flag==1){
        sum=a+c+maior;
    }
    if(flag==2){
        sum = a+b+maior;
    }

    cout << sum << endl;


    return 0;
}
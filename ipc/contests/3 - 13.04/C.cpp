#include<iostream>

using namespace std;

int main(){

    int ant[5],k;

    for(int i=0;i<5;i++){
        cin>>ant[i];
    }
    cin>>k;

    for(int i=0;i<5;i++){
        for(int j=1;j<5;j++){
            if(ant[j]-ant[i]>k){
                cout<<":(\n";
                return 0;
            }
        }
    }

    cout<<"Yay!\n";


    return 0;
}
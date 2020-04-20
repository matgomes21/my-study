#include<iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int order[5],less,lessi=0,sum=0;

    for(int i=0;i<5;i++){
        cin>>order[i];
        if(i==0)less = order[i]%10;
        else{
            if(order[i]%10<less&&order[i]%10>0){
                less = order[i]%10;
                lessi = i;
            }
        }
    }

    for(int i=0;i<5;i++){
        if(i!=lessi){
            while(order[i]%10!=0){
                order[i]++;
            }
            sum+=order[i];
        }
        else sum+=order[i];
    }

    cout<<sum<<endl;
    


    return 0;
}
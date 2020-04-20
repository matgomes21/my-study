#include<iostream>
#include<cstdlib>

using namespace std;

int sum_less(int *v,int t){
    int sum=0;
    for(int i=t;i>=0;i--){
        sum+=v[i];
    }
    return sum;
}

int sum_great(int *v,int t,int n){
    int sum=0;
    for(int i=t+1;i<n;i++)
        sum+=v[i];
    return sum;
}

int main(){

    ios::sync_with_stdio(false);

    int n,*w,less,dif;

    cin>>n;

    w = (int*) malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        cin>>w[i];
    }

    for(int t=0;t<n;t++){
        if(t==0){
            less = sum_great(w,t,n)-sum_less(w,t);
            if(less<0)
                less*=-1;
        }
        else{
            dif = sum_great(w,t,n) - sum_less(w,t);
            if(dif<0)
                dif*=-1;
            if(dif<less)
                less = dif;
        }
    }

    cout<<less<<endl;

    return 0;
}
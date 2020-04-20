#include<iostream>
#include<cstdlib>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int n,*a,*d,div,k;

    cin>>n;

    a = (int*) malloc(n*sizeof(int));
    d = (int*) malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            div=1;
            k=0;
            if(j==i)j++;
            while(div<=a[j]){
                if(a%div==0){
                    d[k] = div;
                    k++;
                }
            } 

        }
    }

    return 0;
}
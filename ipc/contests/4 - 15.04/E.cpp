#include<iostream>
#include<cstdlib>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int n,*v,*c;
    int x=0,y=0;

    cin>>n;

    v = (int*) malloc(n*sizeof(int));
    c = (int*) malloc(n*sizeof(int));

    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        cin>>c[i];
        if(c[i]<v[i]){
            x+=v[i];
            y+=c[i];
        }
    }

    cout<<x-y<<endl;

    return 0;
}
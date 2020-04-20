#include<iostream>
#include<cstdlib>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    int n,m,*hole,j=0,pass=1;

    cin>>n>>m;

    hole = (int*) malloc(m*sizeof(int));

    for(int i=0;i<m;i++)
        cin>>hole[i];

    for(int i=0;i<n;i++){
        if(i+1==hole[j]&&i+2==hole[j+1]&&j+1<m){
            cout<<"0\n";
            return 0;
        }
        else if(i+2==hole[j]);
        else if(i+1==hole[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
        pass++;
    }

    cout<<pass%1000000007<<endl;

    return 0;
}
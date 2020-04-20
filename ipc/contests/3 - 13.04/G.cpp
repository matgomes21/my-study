#include<iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    char s[100000];
    int cont1=0,cont2=0;

    cin>>s;

    for(int i=0;s[i]!='\0';i++){
        if(i%2==0){
            if(s[i]=='1'){
                cont2++;
            }
            else{
                cont1++;
            }
        }
        else{
            if(s[i]=='1'){
                cont1++;
            }
            else{
                cont2++;
            }
        }
    }

    if(cont1<cont2)cout<<cont1<<endl;
    else cout<<cont2<<endl;

    return 0;
}
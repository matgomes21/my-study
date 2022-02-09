#include<iostream>

using namespace std;

int main() {
  int t, x;

  cin >> t;

  for(int i=0; i<t; i++){
    cin >> x;

    if(x%4==0){
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
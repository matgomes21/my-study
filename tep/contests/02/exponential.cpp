#include<iostream>

using namespace std;

int main() {
  double n, sum=1;

  cin >> n;

  for(int i=0;i<n;i++){
    sum*=2;
  }

  if(sum>(n*n))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
#include<iostream>

using namespace std;

int main() {
  double n;
  long long int div=1, sum=0, ten=1, j=1;
  cin >> n;

  for(double i=n/10;i>=1;i/=10){
    div++;
  }

  for(;ten<=n;ten++){
    for(long long int i=ten;i>0;i/=10){
      sum+=i%10;
    }
    if(j<div){
      j++;
      ten*=10;
    }
  }

  cout << sum << endl;

  return 0;
}
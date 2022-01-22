#include<iostream>

using namespace std;

int main() {
  long long int n,a,b,sum=0;
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> a;
    cin >> b;
    sum+= ((a+b)*(b-a+1))/2;
  }
  cout << sum << endl;

  return 0;
}
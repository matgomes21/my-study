#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<stdio.h>

using namespace std;

int main() {
  long long int n, x, xabs, bigger;
  double man=0, euc=0;


  cin >> n;


  for(int i=0;i<n;i++){
    cin >> x;
    xabs = abs(x);

    // chebyshev
    if(i==0 || xabs>bigger){
      bigger = xabs;
    }

    // manhattan
    man+=xabs;

    //euclidian
    euc+=xabs*xabs;
  }

  cout.precision(16);

  cout << man << endl;
  printf("%.15lf\n", sqrt(euc));
  cout << bigger << endl;

  return 0;
}
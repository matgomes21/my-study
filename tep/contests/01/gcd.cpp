#include <iostream>
#include <stdlib.h>

template<typename T>
struct Point {
  T x,y;

  Point(T xv=0, T yv=0) : x(xv), y(yv) {}
};

using namespace std;

int main() {
  int n, *div, x;

  Point<int> bigger;

  cin >> n;

  div = (int *)calloc(1001, sizeof(int));

  for(int i=0; i<n; i++){
    cin >> x;

    for(int j=2; j<=x; j++){
      if(x%j==0){
        div[j]++;
      }
      if(div[j]>bigger.x){
        bigger.x = div[j];
        bigger.y = j;
      }
    }
  }

  cout << bigger.y << endl;

  return 0;
}
#include<iostream>

using namespace std;

template<typename T>
struct Point {
  T x,y;

  Point(T xv=0, T yv=0) : x(xv), y(yv) {}
};

int main() {
  int n;

  Point<int> balls;

  cin >> n >> balls.x >> balls.y;

  cout << n-balls.x+balls.y << endl;

  return 0;
}
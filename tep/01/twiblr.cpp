#include <iostream>

template<typename T>
struct Point {
  T x,y;

  Point(T xv=0, T yv=0) : x(xv), y(yv) {}
};

using namespace std;

int main() {
  Point<int> p;

  cin >> p.x >> p.y;

  cout << (2*p.x + 100) - p.y << endl;

  return 0;
}
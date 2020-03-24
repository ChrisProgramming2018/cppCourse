// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>

#include <assert.h>

// TODO: Define Point class
class Vector {
 public:
  // TODO: Define public constructor
  Vector(int x = 0, int y = 0) : x(x), y(y) {}

  // TODO: Define + operator overload
  Vector operator+(const Vector& addend) {
    Vector sum;
    sum.x = x + addend.x;
    sum.y = y + addend.y;
    return sum;
  }
  Vector operator-(const Vector& subtract) {
    Vector sum;
    sum.x = x - subtract.x;
    sum.y = y - subtract.y;
    return sum;
  }

  // TODO: Declare attributes x and y
  int x, y;
};

// Test in main()
int main() {
  Vector v1(10, 5), v2(2, 4);
  Vector v3 = v1 + v2; // An example call to "operator +";
  assert(v3.x == v1.x + v2.x);
  assert(v3.y == v1.y + v2.y);
}

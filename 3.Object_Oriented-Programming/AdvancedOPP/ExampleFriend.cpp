// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


// Example solution for Rectangle and Square friend classes
#include <assert.h>
#include <iostream>

// Declare class Rectangle
class Rectangle;

// Define class Square as friend of Rectangle
class Square {
 // Add public constructor to Square, initialize side
 public:
  Square(int s) : side(s) {}

 private:
  // Add friend class Rectangle
  friend class Rectangle;
  // Add private attribute side to Square
  int side;
  int _size {5};
};

// Define class Rectangle
class Rectangle {
 // Add public functions to Rectangle: area() and convert()
 public:
  Rectangle(const Square& a);
  void test (const Square& a);
  int Area() const;
 private:
  // Add private attributes width, height
  int width {0};
  int height {0};
};

// Define a Rectangle constructor that takes a Square
Rectangle::Rectangle(const Square& a) : width(a.side), height(a.side) {}

// Define Area() to compute area of Rectangle
int Rectangle::Area() const {
  return width * height;
}

void Rectangle::test(const Square &s) {
  std::cout << "use the member variable of the friend class " << s._size << std::endl;
}


// Update main() to pass the tests
int main() {
  Square square(4);
  Rectangle rectangle(square);
  rectangle.test(square);
  assert(rectangle.Area() == 16);
}

// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>

// Example solution for Shape inheritance
#include <assert.h>
#include <iostream>
#include <string>
#include <cmath>

#define PI 3.14159;

class Shape {
 public:
  virtual double Area() const = 0;
  virtual double Perimeter() const = 0;
};

class Rectangle : public Shape {
 public:
  Rectangle(double width, double height) : width_(width), height_(height) {}
  double Area() const override { return width_ * height_; }
  double Perimeter() const override { return 2 * (width_ + height_); }

 private:
  double width_;
  double height_;
};

class Circle : public Shape {
 public:
  Circle(double radius) : radius_(radius) {}
  double Area() const override { return pow(radius_, 2) * PI; }
  double Perimeter() const override { return 2 * radius_ * PI; }

 private:
  double radius_;
};


// cant use class it needs to have a Area and Perimeter functions 
// if I want to Inherite from Shape becaause they are virtual 
class  Own : public Shape {
 public:
  std::string _name;
  double Area();
  double Perimeter();
  Own(std::string name) { _name = name;}
};
// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality
  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}

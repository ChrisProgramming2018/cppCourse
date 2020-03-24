// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include <iostream>
#include <ctime>

class Date {
 public:
  Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}
  Date(int day, int month) : day_(day), month_(month) {
    // automatically sets the Date to the current year 
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    year_ = timePtr->tm_year;
  }

 private:
  int day_;
  int month_;
  int year_;
};


class Human {};
class Dog {};
class Cat {};

// TODO: Write hello() function
void hello() { std::cout << "Hello, World!\n"; }

// TODO: Overload hello() three times
void hello(Human human) { std::cout << "Hello, Human!\n"; }
void hello(Dog dog) { std::cout << "Hello, Dog!\n"; }
void hello(Cat cat) { std::cout << "Hello, Cat!\n"; }

// TODO: Call hello() from main()
int main() {
  hello();
  hello(Human());
  hello(Dog());
  hello(Cat());
}

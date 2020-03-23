// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>

#include <assert.h>
#include <string>
#include <iostream>

class Person {
 public:
  Person(std::string name) : _name(name) {}
  std::string _name;  
};

class Error {
 public:
  Error(const int number) : _number(number) {}
  int _number;
};
// Test
int main() {
  Person alice("Alice");
  Person bob("Bob");
  assert(alice._name != bob._name);
  Error error(9);
  std::cout << error._number << std::endl;
}

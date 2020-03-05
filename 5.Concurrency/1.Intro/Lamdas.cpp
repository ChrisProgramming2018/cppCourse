// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>



#include <iostream>
#include <algorithm>
#include <vector>


// ______________________________________________________________
void ForEach(const std::vector<int> & values, void(*func)(int)) {
  for(int value : values) 
    func(value);
}


int main() {
  // create lambdas
  int id = 0; // Define an integer variable

  //auto f0 = []() { std::cout << "ID = " << id << std::endl; }; // Error: 'id' cannot be accessed

  id++;
  auto f1 = [id]() { std::cout << "ID = " << id << std::endl; }; // OK, 'id' is captured by value

  id++;
  auto f2 = [&id]() { std::cout << "ID = " << id << std::endl; }; // OK, 'id' is captured by reference

  
  //auto f3 = [id]() { std::cout << "ID = " << ++id << std::endl; }; // Error, 'id' may not be modified

  auto f4 = [id]() mutable { std::cout << "ID = " << ++id << std::endl; }; // OK, 'id' may be modified

  // execute lambdas
  f1();
  f2();
  f4();
  std::vector<int> values = {1,2,3,4,5};
  ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });
  return 0;
}

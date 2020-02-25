// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include<iostream>

class MyClass {
 private:
  int *_number;

 public:
  MyClass() {
    std::cout << "Allocate memory\n";
    _number = (int *)malloc(sizeof(int));
  }
  ~MyClass() {
    std::cout << "Delete memory\n";
    free(_number);
  }
  void setNumber(int number) {
    *_number = number;
    std::cout << "Number: " << _number << "\n";
  }
  int getNumber() {
    return *_number;
  }

};



int main() {
  std::cout << "Start Main " << std::endl;
  //MyClass *myClass = (MyClass *)malloc(sizeof(MyClass));
  //myClass->setNumber(42);
  // std::cout << "Number of class is " << myClass->getNumber() << std::endl;
  // free(myClass);
  
  
  // allocate memory using new
  
  MyClass *myClass = new MyClass();
  myClass->setNumber(42); // works as expected
   std::cout << "Number of class is " << myClass->getNumber() << std::endl;
  delete myClass;
  
  
  return 0;
}


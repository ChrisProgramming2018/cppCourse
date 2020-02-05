// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <string>
#include <cmath>
#include <memory>
#include <chrono>


#ifndef DATARACE_H_
#define DATARACE__H_
class Vehicle {
 public:
  //default constructor
  Vehicle(); 
  //initializing constructor
  Vehicle(int id);

  // setter and getter
  void setID(int id);
  int getID(); 

 private:
  int _id;
};

void example1();

#endif //


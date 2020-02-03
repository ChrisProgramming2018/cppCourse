//
//
//

#include <iostream>
#include <thread>
#include <string>


#ifndef THREAD_H_
#define THREAD_H_

class Vehicle {
 public:
  Vehicle(int id) : _id(id) {}
  void operator()() {
     std::cout << "Vehicle #" << _id << " has been created" << std::endl;
 }
 void example();
 private:
  int _id;
};
#endif //

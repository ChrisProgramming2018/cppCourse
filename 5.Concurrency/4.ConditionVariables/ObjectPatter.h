// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
#include <future>
#include <mutex>

#ifndef THREAD_H_
#define THREAD_H_

class Vehicle {
 public:
  Vehicle(int id);
  int getID();

 private:
  int _id;
};

class WaitingVehicles {
 public:
  WaitingVehicles();
  void printIDs();
  void pushBack(Vehicle &&v);
  Vehicle popBack();
  bool dataIsAvailable();
  int getSizeVehicles();
  int getAmountVehicles();
 
 private:
  std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
  std::mutex _mutex;
  int _amountVehicles;
};

void example();
void example2();
#endif //


// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include "./DataRaces.h"



// ______________________________________________________________
Vehicle::Vehicle() : _id(0) {
  std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl;
}
  
// ______________________________________________________________
Vehicle::Vehicle(int id) : _id(id) {
  //initializing constructor
  std::cout << "Vehicle #" << _id << " Initializing constructor called" << std::endl;
}

// ______________________________________________________________
void Vehicle::setID(int id) {
  _id = id; 
}

// ______________________________________________________________
int Vehicle::getID() { 
  return _id; 
}

// ______________________________________________________________
void example1() {
  // create instances of class Vehicle
  Vehicle v0; // default constructor
  Vehicle v1(1); // initializing constructor

  // read and write name in different threads (which one of the above creates a data race?)
  std::future<void> ftr = std::async([](Vehicle v) {
      std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
      v.setID(2);
      }, v0);

  v0.setID(3);

  ftr.wait();
  std::cout << "Vehicle #" << v0.getID() << std::endl;
}

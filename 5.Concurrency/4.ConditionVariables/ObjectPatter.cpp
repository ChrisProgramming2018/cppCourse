// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include "./ObjectPatter.h"

// ______________________________________________________________
void WaitingVehicles::printIDs() {
  std::lock_guard<std::mutex> myLock(_mutex); // lock is released when myLock goes out of scope
  for(auto &v : _vehicles)
    std::cout << "   Vehicle #" << v.getID() << " is now waiting in the queue" << std::endl;
}

// ______________________________________________________________
void WaitingVehicles::pushBack(Vehicle &&v) {
  // perform vector modification under the lock
  std::lock_guard<std::mutex> uLock(_mutex);
  std::cout << "   Vehicle #" << v.getID() << " will be added to the queue" << std::endl; 
  _vehicles.emplace_back(std::move(v));

  // simulate some work
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}


// ______________________________________________________________
void example() {
  std::cout << "Spawning threads..." << std::endl;
  // create monitor object as a shared pointer to enable access by multiple threads
  std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

  std::cout << "Spawning threads..." << std::endl;
  std::vector<std::future<void>> futures;
  for (int i = 0; i < 10; ++i) {
    // create a new Vehicle instance and move it into the queue
    Vehicle v(i);
    futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
  }

  std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
      ftr.wait();
      });

  std::cout << "Collecting results..." << std::endl;
  queue->printIDs();
}



// ______________________________________________________________
Vehicle::Vehicle(int id) : _id(id) {}

// ______________________________________________________________
int Vehicle::getID() { 
  return _id; 
}

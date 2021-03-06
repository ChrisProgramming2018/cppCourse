// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include "./ObjectPatter.h"
  

// ______________________________________________________________
WaitingVehicles::WaitingVehicles() {
  _amountVehicles = 0;
}

// ______________________________________________________________
int WaitingVehicles::getAmountVehicles() {
  return _amountVehicles;
}

// ______________________________________________________________
bool WaitingVehicles::dataIsAvailable() {
  std::lock_guard<std::mutex> myLock(_mutex);
  return !_vehicles.empty();
}

// ______________________________________________________________
Vehicle WaitingVehicles::popBack() {
  std::lock_guard<std::mutex> uLock(_mutex);

  Vehicle v = std::move(_vehicles.back());
  _vehicles.pop_back();
  _amountVehicles--;
  return v;
}

// ______________________________________________________________
void WaitingVehicles::printIDs() {
  std::lock_guard<std::mutex> myLock(_mutex); // lock is released when myLock goes out of scope
  for(auto &v : _vehicles)
    std::cout << "   Vehicle #" << v.getID() << " is now waiting in the queue" << std::endl;
}

// ______________________________________________________________
void WaitingVehicles::pushBack(Vehicle &&v) {
  // perform vector modification under the lock
  // simulate some work
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::lock_guard<std::mutex> uLock(_mutex);
  _amountVehicles++;
  std::cout << "   Vehicle #" << v.getID() << " will be added to the queue" << std::endl; 
  _vehicles.emplace_back(std::move(v));

}

// ______________________________________________________________
Vehicle::Vehicle(int id) : _id(id) {}

// ______________________________________________________________
int Vehicle::getID() { 
  return _id; 
}

// ______________________________________________________________
int WaitingVehicles::getSizeVehicles() {
  return _vehicles.size();
}

// ______________________________________________________________
void example() {
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
void example2() {
  // create monitor object as a shared pointer to enable access by multiple threads
  std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

  std::cout << "Spawning threads..." << std::endl;
  std::vector<std::future<void>> futures;
  for (int i = 0; i < 10; ++i) {
    // create a new Vehicle instance and move it into the queue
    Vehicle v(i);
    futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
  }
  std::cout << "Collecting results..." << std::endl;
  while (true) {
    if(queue->dataIsAvailable()) {
      Vehicle v = queue->popBack();
      std::cout << " Vehicle #" << v.getID() << " has been removed from the queue " <<  std::endl;
      std::cout << " Size of queue" << queue->getSizeVehicles()  <<  std::endl;
      if (queue->getAmountVehicles() <= 0) {break;}
    }
  }
        
  std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
      ftr.wait();
      });
  

  std::cout << "Finished processing queue" << std::endl;
  std::cout << " Size of queue" << queue->getSizeVehicles()  <<  std::endl;

  // queue->printIDs();
}



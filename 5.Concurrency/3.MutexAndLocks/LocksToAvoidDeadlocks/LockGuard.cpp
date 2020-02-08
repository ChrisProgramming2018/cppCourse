// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include "./LockGuard.h"
#include "./UniqueLock.h"




// ______________________________________________________________
void divideByNumberLockguard(double num, double denom) {
  try {
    // divide num by denom but throw an exception if division by zero is attempted
    if (denom != 0) {
      std::lock_guard<std::mutex> lck(mtx);  // locks 
            
      result = num / denom;
      std::this_thread::sleep_for(std::chrono::milliseconds(1)); 
      printResult(denom);
    } else {
      throw std::invalid_argument("Exception from thread: Division by zero!");
    }
  } catch (const std::invalid_argument &e) {
    // notify the user about the exception and return
    std::cout << e.what() << std::endl;
  }
}

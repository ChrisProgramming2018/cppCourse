// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include "./UniqueLock.h"

std::mutex mtx;
double result;

// ______________________________________________________________
void printResult(int denom) {
  std::cout << "for denom = " << denom << ", the result is " << result << std::endl;
}

// ______________________________________________________________
void divideByNumber(double num, double denom) {
  std::unique_lock<std::mutex> lck(mtx);
  try {
    // divide num by denom but throw an exception if
    // // division by zero is attempted
    if (denom != 0) {
      result = num / denom;
      std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
      printResult(denom);
      lck.unlock();
      // do something outside of the lock
      std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
      lck.lock(); 
      // do someting else under the lock
      std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    } else {
      throw std::invalid_argument("Exception from the thread Division by zero");
    }
  } catch (const std::invalid_argument &e) {
    // notify user about exception and return
    std::cout << e.what() << std::endl;
    return; 
  }
}


// ______________________________________________________________
void example() {
  // create a number of threads wich execute function "divideByNumber" with
  // varying parameters 

  std::vector<std::future<void>> futures;

  for (double i = -5; i <= +5; i++) {
    futures.emplace_back(std::async(std::launch::async, divideByNumber, 50.0,i ));
  }
  std::for_each(futures.begin(), futures.end(), [] (std::future<void> &ftr) {
      ftr.wait();
      });
}

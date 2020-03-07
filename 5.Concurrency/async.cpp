// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>

#include <iostream>
#include <thread>
#include <future>
#include <cmath>

#include <memory>
double divideByNumber(double num, double denom) {
  std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;

  std::this_thread::sleep_for(std::chrono::milliseconds(10000)); // simulate work
  if (denom == 0)
    throw std::runtime_error("Exception from thread: Division by zero!");
  return num / denom;
}


int main() {
  // use async to start a task
  std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;
  double num = 42.0, denom = 2.0;
  std::future<double> ftr = std::async(divideByNumber, num, denom);
  std::future<double> ftr2 = std::async(divideByNumber, num, 5);
  
  for (int i = 0; i < 20; i++) {
  std::cout << " End Main Count " << i << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // simulate work
  }

  double result1 = ftr2.get();
  std::cout << "Result = " << result1 << std::endl;
  // retrieve result within try-catch-block
  try {
    double result = ftr.get();
    std::cout << "Result = " << result << std::endl;
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }
  
  ftr = std::async(divideByNumber, num, 0);
  try {
    double result = ftr.get();
    std::cout << "Result = " << result << std::endl;
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }
  for (int i = 0; i < 10; i++) {
  std::cout << " End Main Count " << i << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // simulate work
  }
  std::cout << " End Main = " << std::this_thread::get_id() << std::endl;
  
  return 0;
}

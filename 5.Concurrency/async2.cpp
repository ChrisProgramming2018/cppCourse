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

  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // simulate work
  if (denom == 0)
    throw std::runtime_error("Exception from thread: Division by zero!");
  return num / denom;
}


int main() {
  // use async to start a task
  std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;
  double num = 42.0, denom = 2.0;
  std::future<double> ftr = std::async(divideByNumber, num, denom);
  


  while (true) {
    std::cout << "  Main Count "  << std::endl;
    ftr = std::async(divideByNumber, num, denom);
    double result = ftr.get();
    std::cout << "Result = " << result << std::endl;
  }
  return 0;
}

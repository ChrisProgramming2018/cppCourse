// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>

#include "./LockGuard.h"


int main() {
  std::cout << "Start Main " << std::endl;
  // create a number of threads which execute the function "divideByNumber" with varying parameters
  std::vector<std::future<void>> futures;
  double a = -5.0;
  for (double i = -5; i <= +5; i++) {
    a = a + 0.1;
    futures.emplace_back(std::async(std::launch::async, divideByNumber, 50.0, a));
  }

  // wait for the results
  std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
      ftr.wait();
      });

  return 0;
}

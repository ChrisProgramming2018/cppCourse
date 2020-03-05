#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>



// ___________________________________________________________________________________________________________________________________________________
void example1() {
  std::cout << "Hello concurrent world from main! Thread id = " << std::this_thread::get_id() << std::endl;
  std::cout << "Hello concurrent world from main! Thread id = " << std::this_thread::get_id() << std::endl;
  
}


// ___________________________________________________________________________________________________________________________________________________
void example2() {
  unsigned int nCores = std::thread::hardware_concurrency();
  std::cout << "This machine supports concurrency with " << nCores << " cores available" << std::endl;
}

int main() {
  
  std::vector<std::thread> threads;

  for (int i = 0; i < 10; i++) {
    threads.emplace_back(std::thread( []() {
        while (true);
        }));
  }

  std::for_each(threads.begin(), threads.end(), [] (std::thread &t) {
      t.join();
      });
  return 0;
  // example1();
  // example2();
}

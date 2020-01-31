#include <iostream>
#include <thread>




void example1() {
  std::cout << "Hello concurrent world from main! Thread id = " << std::this_thread::get_id() << std::endl;
  std::cout << "Hello concurrent world from main! Thread id = " << std::this_thread::get_id() << std::endl;
  
}



void example2() {
  unsigned int nCores = std::thread::hardware_concurrency();
  std::cout << "This machine supports concurrency with " << nCores << " cores available" << std::endl;
}
int main() {
  example1();
  example2();
}

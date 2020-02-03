//
//
//

#include "./Thread_5_Examples.h"


// _____________________________________________________________
void printName(std::string name, int waitTime) {
  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
  std::cout << "Name (from Thread) = " << name << std::endl;
}

// ______________________________________________________________
void VariadicTemplates() {
  std::cout << " start VariadicTemplates " << std::endl;
  std::string name1 = "MyThread1";
  std::string name2 = "MyThread2";

  // starting threads using value-copy and move semantics
  std::thread t1(printName, name1, 50);
  std::thread t2(printName, std::move(name2), 100);

  // wait for threads before returning
  t1.join();
  t2.join();

  // print name from main
  std::cout << "Name (from Main) = " << name1 << std::endl;
  std::cout << "Name (from Main) = " << name2 << std::endl;
}


// _____________________________________________________________
void printID(int id) {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "ID = " << id << std::endl;
}

// _____________________________________________________________
void printIDAndName(int id, std::string name) {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "ID = " << id << ", name = " << name << std::endl;
}

// _____________________________________________________________
void printIDAndNameDefault(int id, std::string name="default") {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "ID = " << id << ", default  name = " << name << std::endl;
}

// _____________________________________________________________
void defaultParameterExample() {
  std::cout << " start Default parameter " << std::endl;

  int id = 0; // Define an integer variable

  // starting threads using variadic templates
  std::thread t1(printID, id);
  std::thread t2(printIDAndName, ++id, "MyString");
  //std::thread t3(printIDAndNameDefault, ++id); // this procudes a compiler error
  // std::thread t3(printIDAndName, ++id); // default parameter to possible
  printIDAndNameDefault(0);   // This works
  // wait for threads before returning
  t1.join();
  t2.join();
  //t3.join();
}

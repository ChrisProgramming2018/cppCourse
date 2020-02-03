//
//
//

#include "./Thread_5.h"




// ______________________________________________________________
void  Vehicle::example() {
  // compiler could it interpreted as 1. a variable definition
  // 2. a function declaration t that returns a type of thread
  // std::thread t(Vehicle());  // would create an error
 
  //  there are 3 methods all of them will copie the object to
  //  internal storage accessible to the thread
 
  // first method to avoid error add pair of ex
  std::thread t((Vehicle(1)));
 
  // use a copy int
  std::thread t2 = std::thread(Vehicle(2));
 
  // use bracets for uniform
  std::thread t3 {(Vehicle(3))};

  // do something
  std::cout << "end of example " << std::endl;
 
  // wait for thread to finish
  t.join();
  t2.join();
  t3.join();
}

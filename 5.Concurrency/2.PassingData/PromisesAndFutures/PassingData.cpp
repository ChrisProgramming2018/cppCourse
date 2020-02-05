// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include "./PassingData.h"

// ______________________________________________________________
void printMessage(std::string message) {
  std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
  std::cout << "Thread 1: " << message << std::endl;
  message = "changed";  // will not be changed out side
}

// ______________________________________________________________
void example1() {
  std::cout << " Start example 1 " <<  std::endl;
  // define message
  std::string message = "My Message";

  // start thread using variadic templates
  std::thread t1(printMessage, message);

  // start thread using a Lambda
  std::thread t2([message] {
  std::this_thread::sleep_for(std::chrono::milliseconds(30)); // simulate work
  std::cout << "Thread 2: " << message << std::endl;
  // message = "changed"; not possible compiler error
  });

  std::cout << "Main : " << message << std::endl;
  // thread barrier
  t1.join();
  t2.join();
  std::cout << "Main after join : " << message << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
  std::cout << "Main after join : " << message << std::endl;
  std::cout << " Ende example 1 " <<  std::endl;
}

// ______________________________________________________________
void modifyMessage(std::promise<std::string> && prms, std::string message) {
  std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // simulate work
  std::string modifiedMessage = message + " has been modified"; 
  prms.set_value(modifiedMessage);  // to see the modification outside the function
}

// ______________________________________________________________
void example2() {
  std::cout << " Start example 2 " <<  std::endl;
  // define message
  std::string messageToThread = "My Message";

  // create promise and future
  std::promise<std::string> prms;
  std::future<std::string> ftr = prms.get_future();

  // start thread and pass promise as argument
  std::thread t(modifyMessage, std::move(prms), messageToThread);

  // print original message to console
  std::cout << "Original message from main(): " << messageToThread << std::endl;

  // retrieve modified message via future and print to console
  std::string messageFromThread = ftr.get();  // only possible one time  
  std::cout << "Modified message from thread(): " << messageFromThread << std::endl;

  // thread barrier
  t.join();
  std::cout << " End example 2 " <<  std::endl;
}


// ______________________________________________________________
void computeSqrt(std::promise<double> &&prms, double input) {
  std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // simulate work
  double output = sqrt(input);
  prms.set_value(output);
}

// ______________________________________________________________
void example3() {
  std::cout << " Start example 3 " <<  std::endl;
  // define input data
  double inputData = 42.0;

  // create promise and future
  std::promise<double> prms;
  std::future<double> ftr = prms.get_future();

  // start thread and pass promise as argument
  std::thread t(computeSqrt, std::move(prms), inputData);

  // Student task STARTS here
  // wait for result to become available
  auto status = ftr.wait_for(std::chrono::milliseconds(1000));
  if (status == std::future_status::ready) {  // result is ready 
    std::cout << "Result = " << ftr.get() << std::endl;
  }  else if (status == std::future_status::timeout || status == std::future_status::deferred) {
   //  timeout has expired or function has not yet been started
  std::cout << "Result unavailable" << std::endl;
  }
  // Student task ENDS here

  // thread barrier
  t.join();
  std::cout << " End example 3 " <<  std::endl;
}


// ______________________________________________________________
void divideByNumber(std::promise<double> &&prms, double num, double denom) {
  std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
  try {
    if (denom == 0) 
      throw std::runtime_error("Exception from thread: Division by zero!");
     else 
      prms.set_value(num / denom);
  } catch (...) {
    prms.set_exception(std::current_exception());
  }
}


// ______________________________________________________________
void example4() {
  // create promise and future
  std::promise<double> prms;
  std::future<double> ftr = prms.get_future();

  std::promise<double> prms2;
  std::future<double> ftr2 = prms2.get_future();
  
  // start thread and pass promise as argument
  double num = 42.0, denom = 0.0;
  std::thread t(divideByNumber, std::move(prms), num, denom);
  std::thread t2(divideByNumber, std::move(prms2), num, 2);
  t2.join();

  // retrieve result within try-catch-block
  try {
    double result = ftr2.get();
    std::cout << "Result = " << result << std::endl;
   } catch (std::runtime_error e) {
     std::cout << e.what() << std::endl;
   }

    // thread barrier
    t.join();
}

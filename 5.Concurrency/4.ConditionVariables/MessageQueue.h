// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>

#include <iostream>
#include <algorithm>
#include <thread>
#include <deque>
#include <vector>
#include <future>
#include <mutex>

#ifndef CONCURRENTMESSAGE_H_
#define CONCURRENTMESSAGE_H_


template<class T>
class MessageQueue {
 public:
  MessageQueue();
  T receive();
  void send(T &&msg);

 private:
  std::mutex _mutex;
  std::condition_variable _cond;
  std::deque<T> _messages; // list of all vehicles waiting to enter this intersection
};
void example_message();
#endif //

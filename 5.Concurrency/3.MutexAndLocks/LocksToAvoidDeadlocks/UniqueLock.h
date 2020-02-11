// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>

#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include<algorithm>


#ifndef THREAD_H_
#define THREAD_H_

extern std::mutex mtx;
extern double result;

void printResult(int denom);
void divideByNumber(double num, double denom);
void example();


#endif //

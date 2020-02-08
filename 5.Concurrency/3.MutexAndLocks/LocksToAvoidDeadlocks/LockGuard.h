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

void divideByNumber(double num, double denom);
void printResult(int denom);

extern std::mutex mtx;
extern double  result;

#endif //


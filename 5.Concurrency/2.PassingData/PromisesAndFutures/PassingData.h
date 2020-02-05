// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <cmath>


#ifndef PASSINGDATA_H_
#define PASSINGDATA_H_

void printMessage(std::string message);
void modifyMessage(std::promise<std::string> && prms, std::string message);
void computeSqrt(std::promise<double> &&prms, double input);
void example1();
void example2();
void example3();
void example4();
#endif //


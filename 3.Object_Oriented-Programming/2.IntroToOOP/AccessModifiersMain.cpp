// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>

#include <cassert>
#include <iostream>

// TODO: Define public accessors and mutators for the private member variables
struct Date {
 public:
  int Day() { return _day; }
  void Day(int day); 
  int Month() { return _month; }
  void Month(int month) { _month = month; }
  int Year() { return _year; }
  void Year(int year) { _year = year; }

 private:
  int _day{1};
  int _month{1};
  int _year{0};
};

void Date::Day(int day)  { 
  assert(day >= 0);
  assert(day <= 31);
  _day = day; 
}

int main() {
  Date date;
  date.Day(29);
  date.Month(8);
  date.Year(1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
  // assert that the value is higher tham 
  // ensure the day is less than 31 and higher than0
  date.Day(0);
  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}

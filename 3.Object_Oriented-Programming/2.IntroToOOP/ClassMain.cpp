// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>

#include <iostream>
#include <cassert>

class Date {
 public:
  int Day() { return day; }
  void Day(int d) {
    if (d >= 1 && d <= 31) day = d;
  }
  int Month() { return month; }
  void Month(int m) {
    if(m >= 1 && m <= 12)
      month = m;
  }
  int getYear() { return year; }
  void setYear(int y) { year = y;}

 private:
  int day{1};
  int month{1};
  int year{0};
};

// Test in main
int main() {
  Date date;
  date.Day(-1);
  date.Month(14);
  date.setYear(2000);
  assert(date.Day() != -1);
  assert(date.Month() != 14);
  assert(date.getYear() == 2000);
  std::cout << date.Day() << "/" << date.Month() << "/" << date.getYear() << "\n";
}

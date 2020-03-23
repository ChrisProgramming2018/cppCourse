// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include <string>
#include <cstring>
#include <iostream>

class Car {
 // TODO: Declare getter and setter for brand
 public:
  void brand(char*);
  std::string brand() const;
 // TODO: Declare private attributes
 private:
  std::string _brand;
        
};

// Define setters
void Car::brand(char* brand) {
  Car::_brand = brand;
}

// Define getters
std::string Car::brand() const {
  return _brand;
}

// Test in main()
int main()  {
  Car car;
  char brand[] = "Peugeot";
  car.brand(brand);
  std::cout << car.brand() << "\n";   
}

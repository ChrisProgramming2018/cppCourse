// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>


#include <iostream>
#include <string>

class BankAccount {
 public:
  int number;
  std::string owner;
  void addMoney(double money, int key); 
  BankAccount(int key);
  double getFunds(int key);
 private:
  double _funds;
  int _key;
};

BankAccount::BankAccount(int key) {
  _key = key;
  _funds = 0.0;
}


void BankAccount::addMoney(double money, int key) {
  if (key == _key) {
    std::cout << "Error false key" << std::endl;
    return;
  }
} 

double BankAccount::getFunds(int key) {
  if (key == _key) return _funds;
  std::cout << "Error false key" << std::endl;
  return 0.0;
}

int main(){
  // TODO: instantiate and output a bank account
  BankAccount account(4050);
  account.number = 123456789;
  account.owner = "Christian Leininger";
 
  std::cout << "Account Information\n";
  std::cout << "-------------------\n";
  std::cout << "ID: " << account.number << "\n";
  std::cout << "Owner: " << account.owner << "\n";
  std::cout << "Funds: $" << account.getFunds(4) << "\n";
}

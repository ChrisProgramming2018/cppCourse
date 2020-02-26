// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>



#include <stdlib.h>
#include <iostream>

class MyMovableClass {
 private:
  int _size;
  int *_data;

 public:
  MyMovableClass(size_t size) {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

   // 1 : destructor
    ~MyMovableClass()  {
      std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
      delete[] _data;
    }

    // copy constructor
    MyMovableClass(const MyMovableClass &source) {
      _size = source._size;
      _data = new int[_size];
      *_data = *source._data;
      std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }
    
    // assignment operator 
    MyMovableClass &operator=(const MyMovableClass &source) {
      std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
      if (this == &source)
        return *this;
      delete[] _data;
      _data = new int[source._size];
      *_data = *source._data;
      _size = source._size;
      return *this;
    }
    
    // move constructor 
    MyMovableClass(MyMovableClass && source) {
      std::cout << "MOVING (c’tor) instance " << &source << " to instance " << this << std::endl;
      _data = source._data;
      _size = source._size;
      source._data = nullptr;
      source._size = 0;
    }
    
    // move assignment operator
    MyMovableClass &operator=(MyMovableClass &&source) {
      std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
      if (this == &source)
        return *this;

      delete[] _data;
      
      _data = source._data;
      _size = source._size;
      
      source._data = nullptr;
      source._size = 0;
      return *this;
    }
};


void example5() {
  std::cout << "move assignment" << std::endl;
  MyMovableClass obj1(100); // constructor
  obj1 = MyMovableClass(200); // move assignment operator
  MyMovableClass obj2 = MyMovableClass(300); // move constructor

}


void example6(){
  std::cout << "copy constructor" << std::endl;
  MyMovableClass obj1(10); // regular constructor
  MyMovableClass obj2(obj1); // copy constructor
  obj2 = obj1; // copy assignment operator

}

void useObject(MyMovableClass obj) {
  std::cout << "using object " << &obj << std::endl;
}

void example7(){
  std::cout << "example 7" << std::endl;
  std::cout << "" << std::endl;
  MyMovableClass obj1(100); // constructor
  useObject(obj1);
}




int main() {
  example6();
  example5();
  example7();
  return 0;
}

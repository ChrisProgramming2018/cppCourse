// Copyright 2020
// cpp course
// Author: Christian Leininger <info2016frei@gmail.com>

#include "./DataRaces.h"

int main(int argc, char** argv) {
  (void)argc;
  (void)argv;


  /// So what should we do?
  int input;
  do {
    std::cout << "\n"
              << "Choose:\n\n"
              << "  (1): \n"
              << "  (2): \n"
              << "  (3): get() vs wait \n"
              << "  (4): Passing exceptions \n"
              << "\n"
              << "Your choice [1-4]: ";
    std::cin >> input;
  } while (input < 1 or input > 4);

  switch (input) {
    case 1: { example1();   break; }
    case 2: { example1();   break; }
    case 3: { example1();   break; }
    case 4: { example1();   break; }
    default: throw std::runtime_error("Invalid choice");
  }


  /// Bye!
  return EXIT_SUCCESS;
}



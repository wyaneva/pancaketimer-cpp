#ifndef MODE_H
#define MODE_H

#include <string>
#include <vector>

struct Mode {
  std::string name;
  int side1;
  int side2;
  int flip;

  bool operator==(Mode const &a) const {
    return a.name == name && a.side1 == side1 && a.side2 == side2 &&
           a.flip == flip;
  }
};

Mode const testmode{"test", 5, 5, 2};
Mode const pancake{"pancake", 85, 60, 5};
Mode const crepe{"crepe", 80, 40, 10};
Mode const emptyMode{"empty", 0, 0, 0};

void printDefaultModes();
Mode const findModeByName(std::string const &modeName);

#endif

#ifndef PANCAKE_TIMER_H
#define PANCAKE_TIMER_H

#include <string>

struct Mode {
  std::string name;
  int side1;
  int side2;
  int flip;
};

int time_pancake(Mode const);

#endif

#ifndef PANCAKE_TIMER_H
#define PANCAKE_TIMER_H

struct Mode {
  int const side1;
  int const side2;
  int const flip;
};

int time_pancake(Mode const);

#endif

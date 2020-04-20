/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "pancaketimer.h"
#include <iostream>

int const side1 = 5;//85;
int const side2 = 5;//60;
int const flip = 5;//5;

int main(int argc, const char *argv[]) {
  std::cout << "Time for pancakes!" << std::endl;
  time_pancake(side1, side2, flip);
  return 0;
}

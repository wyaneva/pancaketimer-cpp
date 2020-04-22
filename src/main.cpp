/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "pancaketimer.h"
#include <iostream>

Mode const testmode{5, 5, 5};
Mode const pancake{85, 60, 5};
Mode const crepe{80, 40, 10};

int main(int argc, const char *argv[]) {
  std::cout << "Time for pancakes!" << std::endl;
  time_pancake(testmode);
  return 0;
}

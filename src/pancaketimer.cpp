/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "pancaketimer.h"
#include <iostream>
#include <chrono>

class PancakeTimer {};

int const time_step = 1;

int time_pancake() {
  int const side1 = 85;
  int const side2 = 60;
  int const flip = 5;

  int threshold = time_step;
  int bar_fill = side1;

  auto start = std::chrono::high_resolution_clock::now();
  while (true) {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tt = end - start;
    auto t = std::chrono::duration_cast<std::chrono::seconds>(tt);
    if (t.count() > threshold) {
      threshold += time_step;
      std::cout << bar_fill << std::endl;
      bar_fill -= time_step;
    }

    if (bar_fill <= 0)
      break;
  }

  return 0;
}

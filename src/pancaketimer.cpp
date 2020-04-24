/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "pancaketimer.h"
#include <iostream>
#include <chrono>

class PancakeTimer {};

int const time_step = 1;
int const total_width = 100;
char const BAR_CHAR = '=';
char const SPACE_CHAR = ' ';

void write_progress(int bar_fill, int total_width, std::string text) {
  std::string fill = "[";

  // fill characters
  for (int i = 0; i < bar_fill; i++) {
    fill += BAR_CHAR;
  }

  // fill space
  for (int i = bar_fill; i < total_width; i++) {
    fill += SPACE_CHAR;
  }
  fill += "]";

  std::cout << fill << std::endl;
}

void run_timer(int const time, bool const do_print) {
  int threshold = time_step;
  int bar_fill = total_width;
  float step = (float)(total_width) / time;

  auto start = std::chrono::high_resolution_clock::now();
  while (true) {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tt = end - start;
    auto t = std::chrono::duration_cast<std::chrono::seconds>(tt);
    if (t.count() > threshold) {
      threshold += time_step;
      if (do_print)
        write_progress(bar_fill, total_width, "");
      bar_fill -= step;
    }

    if (bar_fill < 0) {
      break;
    }
  }
}

int time_pancake(Mode const mode) {

  run_timer(mode.side1, true);
  std::cout << "FLIP!" << std::endl;
  run_timer(mode.flip, false);
  run_timer(mode.side2, true);

  return 0;
}

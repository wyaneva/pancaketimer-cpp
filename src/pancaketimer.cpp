/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "pancaketimer.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>

class PancakeTimer {};

int const time_step = 1;     // seconds
int const total_width = 100; // columns
char const BAR_CHAR = '=';
char const SPACE_CHAR = ' ';

void write_progress(int const bar_width, int const total_width,
                    std::string const text) {
  // calculate spacing for the text in the progress bar
  auto text_len = text.size();
  auto half_width = total_width / 2;
  auto half_text_len_lhs = text_len / 2;
  auto half_text_len_rhs = text_len - half_text_len_lhs;
  int const bar_lhs_const = half_width - half_text_len_lhs;
  auto bar_lhs = std::min(bar_lhs_const, bar_width);
  int const bar_rhs_const = bar_width - half_width - half_text_len_rhs;
  auto bar_rhs = std::max(0, bar_rhs_const);
  auto spacing_lhs = half_width - half_text_len_lhs - bar_lhs;
  auto spacing_rhs = total_width - bar_rhs - half_width - half_text_len_rhs;

  // compose the progress bar
  std::string bar = "[";
  for (int i = 0; i < bar_lhs; i++) {
    bar += BAR_CHAR;
  }
  for (int i = 0; i < spacing_lhs; i++) {
    bar += SPACE_CHAR;
  }
  bar += text;
  for (int i = 0; i < bar_rhs; i++) {
    bar += BAR_CHAR;
  }
  for (int i = 0; i < spacing_rhs; i++) {
    bar += SPACE_CHAR;
  }
  bar += "]";

  // make the progress bar green
  auto green_bar = "\033[32m" + bar + "\033[0m";

  // write the progress bar on the console
  std::cout << green_bar << "\r" << std::flush;
}

void run_timer(int const time, bool const do_print) {
  int threshold = 0;
  int bar_fill = total_width;
  float step = (float)(total_width) / time;
  auto start = std::chrono::high_resolution_clock::now();

  while (bar_fill >= 0) {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tt = end - start;
    auto t = std::chrono::duration_cast<std::chrono::seconds>(tt);
    if (t.count() >= threshold) {
      if (do_print) {
        auto text =
            std::to_string(time - t.count()) + "/" + std::to_string(time);
        write_progress(bar_fill, total_width, text);
      }
      threshold += time_step;
      bar_fill -= step;
    }
  }
}

void time_pancake(Mode const mode) {
  run_timer(mode.side1, true);
  write_progress(0, total_width, "FLIP! FLIP! FLIP!");
  run_timer(mode.flip, false);
  run_timer(mode.side2, true);
}

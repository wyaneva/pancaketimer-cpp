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

void write_progress(int bar_width, int total_width, std::string text) {
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
  std::string fill = "[";
  for (int i = 0; i < bar_lhs; i++) {
    fill += BAR_CHAR;
  }
  for (int i = 0; i < spacing_lhs; i++) {
    fill += SPACE_CHAR;
  }
  fill += text;
  for (int i = 0; i < bar_rhs; i++) {
    fill += BAR_CHAR;
  }
  for (int i = 0; i < spacing_rhs; i++) {
    fill += SPACE_CHAR;
  }
  fill += "]";

  // write the progress bar on the console
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
      if (do_print) {
        auto text =
            std::to_string(time - t.count() + 2) + "/" + std::to_string(time);
        write_progress(bar_fill, total_width, text);
      }
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

/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "pancaketimer.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>

#if __linux__
#define VLC "cvlc"
#elif __APPLE__
#define VLC "/Applications/VLC.app/Contents/MacOS/VLC"
#endif

int const time_step = 1; // seconds
int const total_width = 100;   // columns
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
  bar.append(bar_lhs, BAR_CHAR);
  bar.append(spacing_lhs, SPACE_CHAR);
  bar.append(text);
  bar.append(bar_rhs, BAR_CHAR);
  bar.append(spacing_rhs, SPACE_CHAR);
  bar.append("]");

  // make the progress bar green
  auto green_bar = "\033[32m" + bar + "\033[0m";

  // write the progress bar on the console
  std::cout << green_bar << "\r" << std::flush;
}

void beep() {
  std::string command = VLC;
  command.append(" --play-and-exit beep.mov vlc://quit 2> /dev/null");
  system(command.c_str());
}

void run_timer(int const time, bool const do_print) {
  auto threshold = 0;
  auto total_count = time;
  auto count = total_count;
  auto start = std::chrono::high_resolution_clock::now();

  while (count >= 0) {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tt = end - start;
    auto t = std::chrono::duration_cast<std::chrono::seconds>(tt);
    if (t.count() >= threshold) {
      if (do_print) {
        auto text =
            std::to_string(time - t.count()) + "/" + std::to_string(time);
        auto bar_fill = total_width * (count/(float)total_count);
        write_progress(bar_fill, total_width, text);
      }
      threshold += time_step;
      count -= 1;
    }
  }
}

void time_pancake(Mode const mode) {
  run_timer(mode.side1, true);
  write_progress(0, total_width, "FLIP! FLIP! FLIP!");
  beep();
  run_timer(mode.flip, false);
  run_timer(mode.side2, true);
  beep();
}

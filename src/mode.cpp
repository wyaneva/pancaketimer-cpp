/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "mode.h"
#include <iostream>

std::vector<Mode> defaultModes{pancake, crepe};

void printDefaultModes() {
  std::cout << "Available modes are: ";
  for (auto mode : defaultModes) {
    std::cout << mode.name << " ";
  }
  std::cout << std::endl;
}

Mode const findModeByName(std::string const &modeName) {
  for (auto mode : defaultModes) {
    if (modeName == mode.name) {
      return mode;
    }
  }

  return emptyMode;
}

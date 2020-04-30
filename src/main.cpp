/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "argumentparser.h"
#include "pancaketimer.h"
#include <iostream>
#include <vector>

// TODO 1: Function to print accepted arguments -h
// TODO 2: Add repeat count argument
// TODO 3: Add side arguments
// TODO 4: Add sound

Mode const testmode{"test", 5, 5, 5};
Mode const pancake{"pancake", 85, 60, 5};
Mode const crepe{"crepe", 80, 40, 10};
Mode const emptyMode{"empty", 0, 0, 0};

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

int main(int argc, const char *argv[]) {
  Mode mode = pancake;

  ArgumentParser parser(argc, argv);
  if (parser.doesArgumentExist("--mode")) {
    auto modeName = parser.getArgumentValue("--mode");
    mode = findModeByName(modeName);

    if (mode.name == emptyMode.name) {
      std::cout << modeName << " is an invalid mode." << std::endl
                << "Please, provide a valid mode." << std::endl;
      printDefaultModes();
      return 0;
    }
  }

  std::cout << "Time for pancakes!" << std::endl;
  time_pancake(mode);
  return 0;
}

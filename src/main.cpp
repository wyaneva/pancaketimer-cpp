/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "argumentparser.h"
#include "pancaketimer.h"
#include <iostream>
#include <vector>

Mode const testmode{"test", 5, 5, 5};
Mode const pancake{"pancake", 85, 60, 5};
Mode const crepe{"crepe", 80, 40, 10};
Mode const emptyMode{"empty", 0, 0, 0};

std::vector<Mode> defaultModes{pancake, crepe};

Mode const findModeByName(std::string const &modeName) {
  for (auto mode : defaultModes) {
    if (modeName == mode.name) {
      return mode;
    }
  }

  return emptyMode;
}

int main(int argc, const char *argv[]) {
  std::cout << "Time for pancakes!" << std::endl;
  Mode mode = pancake;

  ArgumentParser parser(argc, argv);
  if(parser.doesArgumentExist("--mode")) {
    auto modeName = parser.getArgumentValue("--mode");
    mode = findModeByName(modeName);
  }

  if (mode.name == emptyMode.name) {
    std::cout << "Please, provide a valid mode." << std::endl;
    return 0;
  }

  time_pancake(mode);
  return 0;
}

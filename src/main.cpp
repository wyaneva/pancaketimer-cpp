/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "argumentparser.h"
#include "pancaketimer.h"
#include <iostream>
#include <vector>

// TODO 1: Add repeat count argument; fix cin.ignore()
// TODO 2: Add side arguments
// TODO 3: Function to print accepted arguments -h
// TODO 4: Add sound

Mode const testmode{"test", 5, 5, 2};
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
  ArgumentParser parser(argc, argv);

  Mode mode = pancake;
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

  int repeats = 1;
  if (parser.doesArgumentExist("--repeats")) {
    auto repeatsstr = parser.getArgumentValue("--repeats");

    // TODO: handle std::invalid_argument
    repeats = std::stoi(repeatsstr);
  }

  std::cout << "Time for pancakes!" << std::endl;
  for (int i = 0; i < repeats; i++) {
    time_pancake(mode);
    if (i < repeats - 1) {
      std::cout << "Press Enter to countinue..."<< "\r" << std::flush;
      std::cin.ignore();
    }
  }
  std::cout << "Done! Enjoy your pancakes!" << std::endl;
  return 0;
}

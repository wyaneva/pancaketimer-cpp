/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "argumenthandler.h"
#include "pancaketimer.h"
#include <iostream>
#include <vector>

//TODO: Write tests for "areArgumentsCorrect"

int main(int argc, const char *argv[]) {
  ArgumentHandler argumenthandler(argc, argv);

  if (!argumenthandler.areArgumentsCorrect()) {
    return 0;
  }

  if (argumenthandler.doHelp()) {
    argumenthandler.printHelp();
    return 0;
  }

  auto mode = argumenthandler.getPancakeMode();
  auto repeats = argumenthandler.getRepeats();

  if (mode.name == emptyMode.name || repeats < 1) {
    return 0;
  }

  std::cout << "Time for pancakes!" << std::endl;
  for (int i = 0; i < repeats; i++) {
    time_pancake(mode);
    if (i < repeats - 1) {
      std::cout << "\nPress Enter to countinue..."
                << "\r" << std::flush;
      std::cin.ignore();
    }
  }
  std::cout << std::endl << "Done! Enjoy your pancakes!" << std::endl;
  return 0;
}

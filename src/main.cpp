/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "argumenthandler.h"
#include "pancaketimer.h"
#include <iostream>
#include <vector>

// TODO 3: Function to print accepted arguments -h
// TODO 4: Add sound

int main(int argc, const char *argv[]) {
  ArgumentHandler argumenthandler(argc, argv);

  auto mode = argumenthandler.getPancakeMode();
  auto repeats = argumenthandler.getRepeats();

  if (mode.name == emptyMode.name || repeats < 1) {
    return 0;
  }

  std::cout << "Time for pancakes!" << std::endl;
  for (int i = 0; i < repeats; i++) {
    time_pancake(mode);
    if (i < repeats - 1) {
      std::cout << "Press Enter to countinue..."
                << "\r" << std::flush;
      std::cin.ignore();
    }
  }
  std::cout << std::endl << "Done! Enjoy your pancakes!" << std::endl;
  return 0;
}

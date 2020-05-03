/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "argumenthandler.h"

bool ArgumentHandler::doHelp() {
  return parser.doesArgumentExist("-h") || parser.doesArgumentExist("--help");
}

void ArgumentHandler::printHelp() {
  std::cout
      << "Welcome to Pancake Timer!" << std::endl
      << "To make the perfect pancakes, run ./pancaketimer without arguments."
      << std::endl
      << "For the perfect crepes, run with\t\"--mode crepes\"." << std::endl
      << "To use your own times, run with \t\"--side1 [time] --side2 [time]\"."
      << std::endl
      << "To make repeat pancakes, run with\t\"--repeats [number]\"."
      << std::endl
      << "Good luck!" << std::endl;
}

Mode ArgumentHandler::getPancakeMode() {

  // Set the default mode
  Mode mode = pancake;

  // Figure out if we will use side arguments or mode arguments
  bool useSides = false;
  bool useMode = false;

  // If both sides are supplied, use those
  if (parser.doesArgumentExist("--side1") &&
      parser.doesArgumentExist("--side2")) {
    useSides = true;
  } else {
    // If only one side is supplied, print a message
    if (parser.doesArgumentExist("--side1") ||
        parser.doesArgumentExist("--side2")) {
      std::cout << "Please, provide both --side1 and --side2 or --mode."
                << std::endl;
      return emptyMode;
    }

    // If mode is supplied, use that
    if (parser.doesArgumentExist("--mode")) {
      useMode = true;
    }
  }

  if (useSides) {
    try {
      auto side1 = parser.getArgumentValueInt("--side1");
      auto side2 = parser.getArgumentValueInt("--side2");
      mode.name = "custom";
      mode.side1 = side1;
      mode.side2 = side2;
    } catch (...) {
      return emptyMode;
    }
  } else {
    if (useMode) {
      auto modeName = parser.getArgumentValueStr("--mode");
      mode = findModeByName(modeName);

      if (mode.name == emptyMode.name) {
        std::cout << "\"" << modeName << "\" is an invalid mode." << std::endl
                  << "Please, provide a valid mode." << std::endl;
        printDefaultModes();
        return emptyMode;
      }
    }
  }

  return mode;
}

int ArgumentHandler::getRepeats() {
  int repeats = 1;
  if (parser.doesArgumentExist("--repeats")) {
    try {
      repeats = parser.getArgumentValueInt("--repeats");
    } catch (...) {
      return 0;
    }
  }

  if (repeats < 1) {
    std::cout << "Please, enter a number of repeats greater than 1."
              << std::endl;
    return 0;
  }

  return repeats;
}


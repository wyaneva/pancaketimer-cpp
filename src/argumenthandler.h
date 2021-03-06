#ifndef ARGUMENT_HANDLER_H
#define ARGUMENT_HANDLER_H

#include "argumentparser.h"
#include "mode.h"
#include <iostream>
#include <vector>

class ArgumentHandler{
public:
  // public constructor
  ArgumentHandler(int const &argc, char const *argv[]) : parser(argc, argv){};

  // public functions
  bool areArgumentsCorrect();
  Mode getPancakeMode();
  int getRepeats();
  bool doHelp();
  void printHelp();

private:
  ArgumentParser parser;
};

#endif

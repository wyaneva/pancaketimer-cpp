/*
 * Pancake Timer
 * Vanya Yaneva, 2020
 */

#include "argumentparser.h"
#include <algorithm>

ArgumentParser::ArgumentParser(int const &argc, char const *argv[]) {
  for (int i = 1; i < argc; i++) {
    tokens.push_back(std::string(argv[i]));
  }
}

std::string const
ArgumentParser::getArgumentValueStr(std::string const &option) const {
  auto token = std::find(tokens.begin(), tokens.end(), option);
  if (token != tokens.end() && ++token != tokens.end()) {
    return *token;
  }

  static const std::string empty_string("");
  return empty_string;
}

int const ArgumentParser::getArgumentValueInt(std::string const &option) const {
  auto valuestr = getArgumentValueStr(option);
  try {
    int value = std::stoi(valuestr);
    return value;
  } catch (std::invalid_argument exc){
    std::cout << "Argument \"" + option + "\" is given invalid value." << std::endl;
    throw exc;
  }
}

bool ArgumentParser::doesArgumentExist(std::string const &option) const {
  auto token = std::find(tokens.begin(), tokens.end(), option);
  return token != tokens.end();
}

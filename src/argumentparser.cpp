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

std::string const &
ArgumentParser::getArgumentValue(std::string const &option) const {
  auto token = std::find(tokens.begin(), tokens.end(), option);
  if (token != tokens.end() && ++token != tokens.end()) {
    return *token;
  }

  static const std::string empty_string("");
  return empty_string;
}

bool ArgumentParser::doesArgumentExist(std::string const &option) const {
  auto token = std::find(tokens.begin(), tokens.end(), option);
  return token != tokens.end();
}

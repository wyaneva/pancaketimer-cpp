#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include <iostream>
#include <vector>

class ArgumentParser {
public:
  // public constructor
  ArgumentParser(int const &argc, char const *argv[]);

  // public functions
  std::string const &getArgumentValue(std::string const &option) const;
  bool doesArgumentExist(std::string const &option) const;

private:
  std::vector<std::string> tokens;
};

#endif

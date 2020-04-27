#include "argumentparser.h"
#include "pancaketimer.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(argument_parser_test, does_argument_exist_yes) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "-side1", "80"};
  ArgumentParser parser(argc, argv);

  EXPECT_TRUE(parser.doesArgumentExist("-side1"));
}

TEST(argument_parser_test, does_argument_exist_no) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "-side1", "80"};
  ArgumentParser parser(argc, argv);

  EXPECT_FALSE(parser.doesArgumentExist("-side2"));
}

TEST(argument_parser_test, get_argument_yes) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "-side1", "80"};
  ArgumentParser parser(argc, argv);

  EXPECT_EQ(parser.getArgumentValue("-side1"), "80");
}

TEST(argument_parser_test, get_argument_no) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "-side1", "80"};
  ArgumentParser parser(argc, argv);

  EXPECT_EQ(parser.getArgumentValue("-side2"), "");
}

TEST(time_pancake_test, first_test) {
  Mode const testmode{0, 0, 0};
  EXPECT_EQ(0, time_pancake(testmode));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

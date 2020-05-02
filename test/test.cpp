#include "argumentparser.h"
#include "argumenthandler.h"
#include "pancaketimer.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(argument_parser_test, does_argument_exist_yes) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--side1", "80"};
  ArgumentParser parser(argc, argv);

  EXPECT_TRUE(parser.doesArgumentExist("--side1"));
}

TEST(argument_parser_test, does_argument_exist_no) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--side1", "80"};
  ArgumentParser parser(argc, argv);

  EXPECT_FALSE(parser.doesArgumentExist("--side2"));
}

TEST(argument_parser_test, get_argument_str_yes) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--side1", "80"};
  ArgumentParser parser(argc, argv);

  EXPECT_EQ(parser.getArgumentValueStr("--side1"), "80");
}

TEST(argument_parser_test, get_argument_str_no) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--side1", "80"};
  ArgumentParser parser(argc, argv);

  EXPECT_EQ(parser.getArgumentValueStr("--side2"), "");
}

TEST(argument_parser_test, get_argument_int_yes) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--side1", "80"};
  ArgumentParser parser(argc, argv);

  EXPECT_EQ(parser.getArgumentValueInt("--side1"), 80);
}

TEST(argument_parser_test, get_argument_int_no1) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--side1", "test"};
  ArgumentParser parser(argc, argv);

  EXPECT_ANY_THROW(parser.getArgumentValueInt("--side1"));
}

TEST(argument_parser_test, get_argument_int_no2) {
  int argc = 2;
  char const *argv[2] = {"pancaketimer", "--side1"};
  ArgumentParser parser(argc, argv);

  EXPECT_ANY_THROW(parser.getArgumentValueInt("--side1"));
}

TEST(argument_parser_test, get_argument_int_no3) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--side1", "80"};
  ArgumentParser parser(argc, argv);

  EXPECT_ANY_THROW(parser.getArgumentValueInt("--side2"));
}

TEST(argument_handler_test, get_mode_side1_only) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--side1", "80"};
  ArgumentHandler handler(argc, argv);

  EXPECT_EQ(handler.getPancakeMode().name, emptyMode.name);
}

TEST(argument_handler_test, get_mode_side2_only) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--side2", "80"};
  ArgumentHandler handler(argc, argv);

  EXPECT_EQ(handler.getPancakeMode().name, emptyMode.name);
}

TEST(argument_handler_test, get_mode_side1_and_mode_only) {
  int argc = 5;
  char const *argv[5] = {"pancaketimer", "--side1", "80", "--mode", "pancake"};
  ArgumentHandler handler(argc, argv);

  EXPECT_EQ(handler.getPancakeMode().name, emptyMode.name);
}

TEST(argument_handler_test, get_mode_two_sides_yes) {
  int argc = 5;
  char const *argv[5] = {"pancaketimer", "--side1", "80", "--side2", "40"};
  ArgumentHandler handler(argc, argv);
  auto mode = handler.getPancakeMode();

  EXPECT_EQ(mode.side1, 80);
  EXPECT_EQ(mode.side2, 40);
}

TEST(argument_handler_test, get_mode_two_sides_no) {
  int argc = 4;
  char const *argv[4] = {"pancaketimer", "--side1", "80", "--side2"};
  ArgumentHandler handler(argc, argv);
  auto mode = handler.getPancakeMode();

  EXPECT_EQ(mode.name, emptyMode.name);
}

TEST(argument_handler_test, get_mode_two_sides_and_mode) {
  int argc = 6;
  char const *argv[6] = {"pancaketimer", "--side1", "80", "--side2", "40", "--mode"};
  ArgumentHandler handler(argc, argv);
  auto mode = handler.getPancakeMode();

  EXPECT_EQ(mode.side1, 80);
  EXPECT_EQ(mode.side2, 40);
}

TEST(argument_handler_test, get_mode_mode_yes) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--mode", "pancake"};
  ArgumentHandler handler(argc, argv);
  auto mode = handler.getPancakeMode();

  EXPECT_EQ(mode, pancake);
}

TEST(argument_handler_test, get_mode_mode_no1) {
  int argc = 2;
  char const *argv[2] = {"pancaketimer", "--mode"};
  ArgumentHandler handler(argc, argv);
  auto mode = handler.getPancakeMode();

  EXPECT_EQ(mode, emptyMode);
}

TEST(argument_handler_test, get_mode_mode_no2) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--mode", "invalid"};
  ArgumentHandler handler(argc, argv);
  auto mode = handler.getPancakeMode();

  EXPECT_EQ(mode, emptyMode);
}

TEST(argument_handler_test, get_repeats_yes) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--repeats", "2"};
  ArgumentHandler handler(argc, argv);
  auto rep = handler.getRepeats();

  EXPECT_EQ(rep, 2);
}

TEST(argument_handler_test, get_repeats_no1) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--repeats", "invalid"};
  ArgumentHandler handler(argc, argv);
  auto rep = handler.getRepeats();

  EXPECT_EQ(rep, 0);
}

TEST(argument_handler_test, get_repeats_no2) {
  int argc = 3;
  char const *argv[3] = {"pancaketimer", "--repeats", "0"};
  ArgumentHandler handler(argc, argv);
  auto rep = handler.getRepeats();

  EXPECT_EQ(rep, 0);
}

TEST(argument_handler_test, get_repeats_no3) {
  int argc = 2;
  char const *argv[2] = {"pancaketimer", "--repeats"};
  ArgumentHandler handler(argc, argv);
  auto rep = handler.getRepeats();

  EXPECT_EQ(rep, 0);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

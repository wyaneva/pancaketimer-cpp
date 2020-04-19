#include "pancaketimer.h"
#include "gtest/gtest.h"
#include <iostream>

TEST (time_pancake_test, first_test) {
  EXPECT_EQ(0, time_pancake());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

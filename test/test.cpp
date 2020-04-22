#include "pancaketimer.h"
#include "gtest/gtest.h"
#include <iostream>

TEST (time_pancake_test, first_test) {
  Mode const testmode{0,0,0};
  EXPECT_EQ(0, time_pancake(testmode));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  int res = 1 + 2;
  EXPECT_EQ(res, 3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

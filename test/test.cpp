#include <iostream>
#include "gtest/gtest.h"

  TEST(SimpleTest, Pass) {
    EXPECT_TRUE(true);
  }

  TEST(SimpleTest, Fail) {
    EXPECT_TRUE(false);
  }

  GTEST_API_ int main( int argc, char **argv ) {
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
  }

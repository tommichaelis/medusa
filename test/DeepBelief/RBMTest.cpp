#include <iostream>
#include <gtest/gtest.h>
#include <DeepBelief/RBM.h>

using namespace medusa;

TEST(RBMTest, Construct) {
    RBM rbm = new RBM();
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

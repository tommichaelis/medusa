#include <iostream>
#include <gtest/gtest.h>
#include <Algorithms/NaiveBayes.h>
#include <Exceptions/MatrixSizeException.h>

using namespace medusa;

class NaiveBayesTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            NaiveBayesConfig config;
            naiveBayes = new NaiveBayes( config );
        }
        
        NaiveBayes * naiveBayes;
};

TEST_F(NaiveBayesTest, Learn) {
}

TEST_F(NaiveBayesTest, Run) {
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

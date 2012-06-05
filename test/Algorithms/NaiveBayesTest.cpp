#include <iostream>
#include <gtest/gtest.h>
#include <Algorithms/NaiveBayes.h>
#include <Exceptions/MatrixSizeException.h>

using namespace medusa;

class NaiveBayesTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            NaiveBayesConfig config;
            config.classifierColumn = 0;
            config.sourceDimensions = 5;
            naiveBayes = new NaiveBayes( config );
        }
        
        NaiveBayes * naiveBayes;
};

TEST_F(NaiveBayesTest, Learn) {
    
    mat learnData = "1 2 1 0 0; 1 1 2 0 0; 0 0 0 3 4; 0 0 0 2 5;";
    umat classifier = "1; 1; 2; 2;";
    ASSERT_EQ( 1, naiveBayes->learn( learnData, classifier) );
    
    mat learnData_bad = "1 2 0 0; 1 1 0 0; 0 0 3 4; 0 0 2 5;";
    ASSERT_THROW( naiveBayes->learn( learnData_bad, classifier ), MatrixSizeException );
    
    umat classifier_bad = "1; 1; 2;";
    ASSERT_THROW( naiveBayes->learn( learnData, classifier_bad ), MatrixSizeException );
}

TEST_F(NaiveBayesTest, Run) {
}

TEST_F(NaiveBayesTest, GetInputMatrix) {
    MatrixFormat format = naiveBayes->getInputFormat();
    ASSERT_STREQ( format.format, DOUBLE );
    ASSERT_EQ( format.size, 5 );
    
}

TEST_F(NaiveBayesTest, GetOutputMatrix) {
    MatrixFormat format = naiveBayes->getOutputFormat();
    ASSERT_STREQ( format.format, DOUBLE );
    ASSERT_EQ( format.size, 6 );
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

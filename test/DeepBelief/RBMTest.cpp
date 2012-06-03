#include <iostream>
#include <gtest/gtest.h>
#include <DeepBelief/RBM.h>
#include <Exceptions/MatrixSizeException.h>

using namespace medusa;

class RBMTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            Configuration config;
            config.epsResultBias = 0.3;
            config.epsSourceBias = 0.7;
            config.epsWeights = 0.2;
            config.iterations = 7;
            config.momentum = 0.15;
            config.resultDimensions = 2;
            config.sourceDimensions = 5;
            config.weightCost = 1.1;
            
            rbm = new RBM( config );
        }
        
        RBM * rbm;
};

TEST_F(RBMTest, DoLearn) {
    
    mat input = "1 0 1 1 0; 1 1 0 1 1;";
    int out = rbm->doLearn(input);
    EXPECT_EQ( 1, out );
    
    mat bad_input = "1 0 1 1 1 0; 1 0 0 1 0 1;";
    ASSERT_THROW( rbm->doLearn(bad_input), MatrixSizeException );
     
}

TEST_F(RBMTest, RunForwards) {
    
    mat input = "1 0 1 1 0; 1 1 0 1 1;";
    rbm->doLearn(input);
    
    mat run = "0 1 0 0 1; 0 0 0 1 0; 1 1 0 1 0;";
    mat out = rbm->runForwards(run);
    EXPECT_EQ( 3, out.n_rows );
    EXPECT_EQ( 2, out.n_cols );
    
    mat bad_run = "1, 0, 1;";
    ASSERT_THROW( rbm->runForwards(bad_run), MatrixSizeException );
}

TEST_F(RBMTest, RunBackwards) {
    mat input = "1 0 1 1 0; 1 1 0 1 1;";
    rbm->doLearn(input);
    
    mat run = "0 0; 1 1; 0 1; 1 0; 0 0;";
    mat out = rbm->runBackwards(run);
    EXPECT_EQ( 5, out.n_rows );
    EXPECT_EQ( 5, out.n_cols );
    
    mat bad_run = "1, 0, 1;";
    ASSERT_THROW( rbm->runForwards(bad_run), MatrixSizeException );
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

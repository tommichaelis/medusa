
#Set up some variables for building the tests

TEST_LIB_DIR=./gtest/lib
TEST_INCLUDE_DIR=./gtest/include
TEST_LIB=gtest
TEST_ARGS=-L$(TEST_LIB_DIR) -I$(TEST_INCLUDE_DIR) -lgtest

PROJ_LIB_DIR=../lib
PROJ_INCLUDE_DIR=../include

TESTS=Algorithms/RBMTest.cpp Algorithms/NaiveBayesTest.cpp

ARGS=-L$(PROJ_LIB_DIR) -I$(PROJ_INCLUDE_DIR) -lMedusa -larmadillo $(TEST_ARGS)

#
# Now build the bloody tests
#

buildtest: $(TESTS)

buildsources: $(PROJ_LIB_DIR)/libMedusa.a
	make -C ../


Algorithms/RBMTest.cpp: buildsources
	g++ $(ARGS) Algorithms/RBMTest.cpp -o Algorithms/RBMTest
	
Algorithms/NaiveBayesTest.cpp: buildsources
	g++ $(ARGS) Algorithms/NaiveBayesTest.cpp -o Algorithms/NaiveBayesTest
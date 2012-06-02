
TEST_LIB_DIR=./gtest/lib
TEST_INCLUDE_DIR=./gtest/include
TEST_LIB=gtest
TEST_ARGS=-L$(TEST_LIB_DIR) -I$(TEST_INCLUDE_DIR) -lgtest

buildtest:
	g++ $(TEST_ARGS) test.cpp -o test

runtest:
	./test

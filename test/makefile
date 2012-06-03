
TEST_LIB_DIR=./gtest/lib
TEST_INCLUDE_DIR=./gtest/include
TEST_LIB=gtest
TEST_ARGS=-L$(TEST_LIB_DIR) -I$(TEST_INCLUDE_DIR) -lgtest

PROJ_LIB_DIR=../lib
PROJ_INCLUDE_DIR=../include

ARGS=-L$(PROJ_LIB_DIR) -I$(PROJ_INCLUDE_DIR) -lMedusa -larmadillo $(TEST_ARGS)

buildtest: buildsources
	g++ $(ARGS) DeepBelief/RBMTest.cpp -o DeepBelief/RBMTest


buildsources:
	make -C ../

runtest:
	./test

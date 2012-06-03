INCLUDE_DIR=./include
LIB_DIR=./lib
COMMON_DIRS=-I$(INCLUDE_DIR) -L$(LIB_DIR)

PACKAGES=./DeepBelief/RBM.o

build: $(PACKAGES)
	ar -rv ./lib/libMedusa.a $(PACKAGES)

./DeepBelief/RBM.o: ./DeepBelief/RBM.cpp
	g++ -c $(COMMON_DIRS) ./DeepBelief/RBM.cpp -o ./DeepBelief/RBM.o




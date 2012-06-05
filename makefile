INCLUDE_DIR=./include
LIB_DIR=./lib
COMMON_DIRS=-I$(INCLUDE_DIR) -L$(LIB_DIR)

#--------------------------------------------------------------#
# Add new targets to this list, and their build commands below #
#--------------------------------------------------------------#

PACKAGES=   ./build/Layer.o \
	    ./build/SupervisedLayer.o \
	    ./build/UnsupervisedLayer.o \
	    ./build/Algorithms/RBM.o \
	    ./build/Algorithms/NaiveBayes.o \
	    ./build/FileManager/CSVManager.o

build: prep_build_dir $(PACKAGES)
	ar -rv ./lib/libMedusa.a $(PACKAGES)

prep_build_dir:
	mkdir -p build
	mkdir -p build/Algorithms
	mkdir -p build/FileManager
	mkdir -p lib

clean:
	rm -rf build

#----------------------------#
# Add new targets below here #
#----------------------------#

# The basic layer abstract class
./build/Layer.o: ./Layer.cpp
	g++ -c $(COMMON_DIRS) ./Layer.cpp -o ./build/Layer.o
	
#CSV Loading layer algorithm
./build/FileManager/CSVManager.o: ./FileManager/CSVManager.cpp
	g++ -c $(COMMON_DIRS) ./FileManager/CSVManager.cpp -o ./build/FileManager/CSVManager.o
	
# Abstract class for supervised layers
./build/SupervisedLayer.o: ./SupervisedLayer.cpp
	g++ -c $(COMMON_DIRS) ./SupervisedLayer.cpp -o ./build/SupervisedLayer.o
	
#Abstract class for un-supervised layers
./build/UnsupervisedLayer.o: ./UnsupervisedLayer.cpp
	g++ -c $(COMMON_DIRS) ./UnsupervisedLayer.cpp -o ./build/UnsupervisedLayer.o

#RBM algorithm
./build/Algorithms/RBM.o: ./Algorithms/RBM.cpp
	g++ -c $(COMMON_DIRS) ./Algorithms/RBM.cpp -o ./build/Algorithms/RBM.o
	
#Naive Bayes algorithm
./build/Algorithms/NaiveBayes.o: ./Algorithms/NaiveBayes.cpp
	g++ -c $(COMMON_DIRS) ./Algorithms/NaiveBayes.cpp -o ./build/Algorithms/NaiveBayes.o


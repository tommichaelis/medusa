INCLUDE_DIR=./include
LIB_DIR=./lib
COMMON_DIRS=-I$(INCLUDE_DIR) -L$(LIB_DIR)

#--------------------------------------------------------------#
# Add new targets to this list, and their build commands below #
#--------------------------------------------------------------#

PACKAGES=   ./build/ML_Layer.o \
	    ./build/ML_SupervisedLayer.o \
	    ./build/ML_UnsupervisedLayer.o \
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
./build/ML_Layer.o: ./ML_Layer.cpp
	g++ -c $(COMMON_DIRS) ./ML_Layer.cpp -o ./build/ML_Layer.o
	
#CSV Loading layer algorithm
./build/FileManager/CSVManager.o: ./FileManager/CSVManager.cpp
	g++ -c $(COMMON_DIRS) ./FileManager/CSVManager.cpp -o ./build/FileManager/CSVManager.o
	
# Abstract class for supervised layers
./build/ML_SupervisedLayer.o: ./ML_SupervisedLayer.cpp
	g++ -c $(COMMON_DIRS) ./ML_SupervisedLayer.cpp -o ./build/ML_SupervisedLayer.o
	
#Abstract class for un-supervised layers
./build/ML_UnsupervisedLayer.o: ./ML_UnsupervisedLayer.cpp
	g++ -c $(COMMON_DIRS) ./ML_UnsupervisedLayer.cpp -o ./build/ML_UnsupervisedLayer.o

#RBM algorithm
./build/Algorithms/RBM.o: ./Algorithms/RBM.cpp
	g++ -c $(COMMON_DIRS) ./Algorithms/RBM.cpp -o ./build/Algorithms/RBM.o
	
#Naive Bayes algorithm
./build/Algorithms/NaiveBayes.o: ./Algorithms/NaiveBayes.cpp
	g++ -c $(COMMON_DIRS) ./Algorithms/NaiveBayes.cpp -o ./build/Algorithms/NaiveBayes.o


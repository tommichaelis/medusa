all:

	g++ -c component.cpp

	g++ -c rbm.cpp

	g++ rbm.o component.o -larmadillo deeplearn.cpp -o deeplearn

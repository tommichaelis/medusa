#include <iostream>

#include "rbm.h"
#include "armadillo"

using namespace deeplearn;

int main()
{
	RBM * inputRBM = new RBM(20);
//	RBM * middleRBM = new RBM(20);
//	RBM * outputRBM = new RBM(2);

//	inputRBM->connectComponent(middleRBM);
//	middleRBM->connectComponent(outputRBM);
	
	std::cout << "Starting Learning" << std::endl;
	
//	for( int i = 0; i < 1; i++ ){
		arma::mat learnMat = randu<mat>(5, 5);
		
		learnMat	<< 0 << 0 << 0 << 1 << 1 << endr
					<< 0 << 0 << 0 << 1 << 1 << endr
					<< 0 << 0 << 0 << 1 << 1 << endr
					<< 0 << 0 << 0 << 1 << 1 << endr
					<< 1 << 1 << 0 << 0 << 0 << endr
					<< 1 << 1 << 0 << 0 << 0 << endr
					<< 1 << 1 << 0 << 0 << 0 << endr
					<< 1 << 1 << 0 << 0 << 0 << endr;
										

		

		inputRBM->setSourceMatrix(&learnMat);
		
//		std::cout << learnMat << std::endl;


		inputRBM->learn();
		
/*		learnMat = randu<mat>(5, 5);
		
		for( int j = 0; j < 5; j++ ){
			for( int k = 0; k < 5; k++ ){
				if( j > 2 ){
					learnMat(j,k) = 1;
				}else{
					learnMat(j,k) = 0;
				}
			}
		}
		inputRBM->setSourceMatrix(&learnMat);
		inputRBM->learn();*/
//	}
	std::cout << "Finished Learning" << std::endl;

/*	
	for( int i = 0; i < 5; i++ ){
		arma::mat learnMat = randu<mat>(5, 5);
		for( int j = 0; j < 5; j++ ){
			for( int k = 0; k < 5; k++ ){
				if( j < 2 ){
					learnMat(j,k) = 1;
				}else{
					learnMat(j,k) = 0;
				}
			}
		}
		*/
		
		arma::mat runMat = randu<mat>(5, 5);
		
		runMat		<< 1 << 1 << 0 << 0 << 0 << endr
					<< 0 << 0 << 0 << 1 << 0 << endr
					<< 0 << 0 << 0 << 0 << 1 << endr
					<< 0 << 1 << 0 << 0 << 0 << endr
					<< 1 << 0 << 0 << 1 << 1 << endr
					<< 1 << 1 << 0 << 0 << 0 << endr
					<< 0 << 1 << 0 << 0 << 0 << endr
					<< 1 << 1 << 0 << 1 << 0 << endr;
		
		inputRBM->run( runMat );
		
		/*
		std::cout << outputRBM->getTarget() << std::endl; 
		
		learnMat = randu<mat>(5, 5);
		for( int j = 0; j < 5; j++ ){
			for( int k = 0; k < 5; k++ ){
				if( j > 2 ){
					learnMat(j,k) = 1;
				}else{
					learnMat(j,k) = 0;
				}
			}
		}
		
		inputRBM->run( learnMat );
		std::cout << outputRBM->getTarget() << std::endl; 
	}
	*/
	
	
}
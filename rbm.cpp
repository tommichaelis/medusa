#include "rbm.h"

using namespace arma;
using namespace deeplearn;
using namespace std;
using namespace rbm;

int RBM::doLearn(){
    
	if(0 > preLearn()){ return -1; }

	mat weightIncr = zeros(numDims, numResults);
	mat sourceBiasIncr = zeros(1, numDims);
	mat resultBiasIncr = zeros(1, numResults);
	int err;
	double error = errorThreshold+1;

	while(error > errorThreshold){

		// Set up some empty matrices to fill on this first bit of the step
		mat * resultProbs = new mat();
		mat * jointDensityMatrix = new mat();
		mat * sourceDensity = new mat();
		mat * resultDensity = new mat();
		
        
                Step * step = new Step( sourceMatrix, weights, resultBiases, config );
        
                StepResults forwardsResults = step->forwards();
                StepResults backwardsResults = step->backwards();
                
                mat visible = step->getVisible();
                mat hidden = step->getHidden();
		
                
                
                
                
                
                
                
                
                
                
                
                
		err = stepRBM( 	*sourceMatrix,
						resultBiases, 
						weights,
						resultProbs,
						jointDensityMatrix,
						sourceDensity,
						resultDensity);


		if( 0 > err ){ return -1; }

		
		
		//umat resultStates = ( *resultProbs > randu<mat>(numCases, numResults) );
		umat resultStates = ( *resultProbs > 0.5*randn(numCases, numResults) );

		
		// Create some data from the contents of the weights
		mat createdMatrix 	= 1/( 1 + exp(
								- (resultStates * (weights.t()))
								- repmat( sourceBiases, numCases, 1 )
								)
							);
		/*
		 * These variables are all prefixed with 'neg' - that's because they contribute
		 * to the negative size of the later equation. Run a step to fill 'em in.
		 *
		 * This step essentially takes the data created by the machine and then runs it
		 * through the same algorithm - we can punish where this is a good match and the
		 * corresponding aspect of the real data is a bad match.
		 */
		mat * negResultProbs = new mat();
		mat * negJointDensityMatrix = new mat();
		mat * negSourceDensity = new mat();
		mat * negResultDensity = new mat();
		
		err = stepRBM( 	createdMatrix,
						resultBiases,
						weights,
						negResultProbs,
						negJointDensityMatrix,
						negSourceDensity,
						negResultDensity);
		
		
		if( 0 > err ){ return -1; }

		error = accu(pow(*sourceMatrix-createdMatrix, 2));
		cout << "Error: " << error << endl;

		weightIncr = momentum*weightIncr
						+ ( epsilonWeights
						* ( (*jointDensityMatrix - *negJointDensityMatrix)/numCases
							- weights*weightCost) );

		sourceBiasIncr = momentum*sourceBiasIncr
							+ ( ( epsilonSourceBias/numCases )
							* (*sourceDensity - *negSourceDensity) );


		
		resultBiasIncr = momentum*resultBiasIncr
							+ ( ( epsilonResultBias/numCases )
							* (*resultDensity - *negResultDensity) );
		
		
		weights = weights + weightIncr;
		sourceBiases = sourceBiases + sourceBiasIncr;
		resultBiases = resultBiases + resultBiasIncr;
		
		
		delete resultProbs;
		delete jointDensityMatrix;
		delete sourceDensity;
		delete resultDensity;
		delete negResultProbs;
		delete negJointDensityMatrix;
		delete negSourceDensity;
		delete negResultDensity;

	}

	return 0;
	
}

int RBM::preLearn(){
	if(NULL == sourceMatrix){
		return -1;
	}

	numCases 	= sourceMatrix->n_rows;
	numDims 	= sourceMatrix->n_cols;

	weights 		= 0.1*randn(numDims, numResults);

	resultBiases 	= zeros(1, numResults);
	sourceBiases 	= zeros(1, numDims);

	return 0;
}


int RBM::doRun( mat inputMatrix, mat *returnMatrix ){
	int err;
	mat newMat;
	mat resultProbs;

	
	err = stepRBM(inputMatrix,
				  resultBiases, 
				  weights,
				  &resultProbs,
				  NULL,
				  NULL,
				  NULL);
	
	//umat resultStates = ( *resultProbs > randu<mat>(numCases, numResults) );
	umat resultStates = ( resultProbs > 0.5*randn(numCases, numResults) );
	
	
	// Create some data from the contents of the weights
	mat createdMatrix 	= 1/( 1 + exp(
									  - (resultStates * (weights.t()))
									  - repmat( sourceBiases, numCases, 1 )
									  )
							 );
	cout << createdMatrix << endl;
	//newMat = conv_to<mat>::from( resultProbs > randu<mat>(numCases, numResults));
	returnMatrix = &createdMatrix;
	
	return err;
	
}

/* Do a step in an RBM, from a source level to a target level.
 * Variables are as follows:
 *
 * dataMatrix - is a matrix where each row is a data entry
 *
 * hiddenBiases - is a vector containing biases for each hidden vector
 *
 * weights - is a matrix containing weights between the visible and 
 * hidden variables
 *
 * probabilities - will be set to be a matrix where for each data entry
 * there is a row, and each row contains for each hidden variable the
 * probability it is 1. This will be calculated as
 * 1/(1 + exp(-data*vishid - hidbiases));
 *
 * We will then calculate a matrix which contains for each input point
 * and each hidden variable the number of times they are on together.		
 */

int RBM::stepRBM( 	mat sourceMatrix,
				mat targetBiases,
				mat weights,
				mat * targetProbs,
				mat * jointDensityMatrix,
				mat * sourceDensity,
				mat * targetDensity ){

	/* ADD ERROR CHECKING HERE - RETURN AN ERRNUM IF SIZES DON'T WORK OUT */

	/* This generates some probabilities */
	
	if( NULL != targetProbs ){

		*targetProbs = 1/( 1 + exp(
								   - sourceMatrix*weights
								   - repmat( targetBiases, sourceMatrix.n_rows, 1 )
								   )
						  );
	}
	
	
	/* The following matrix contains information on the proportion of times
	 * each hidden variable is on at the same time as each visible one.
	 */
	if( NULL != targetProbs && NULL != jointDensityMatrix ){
		*jointDensityMatrix = sourceMatrix.t()*(*targetProbs);
	}
	/* Stores the 'onness' of hidden and visible variables on this step */
	if( NULL != targetProbs && NULL != targetDensity ){
		*targetDensity = sum( *targetProbs );
	}
	
	if( NULL != sourceDensity ){
		*sourceDensity = sum( sourceMatrix );
	}
	
 	return 0;

}

/*
 * Construct - set a bunch of fields.
 */

RBM::RBM(	unsigned int inNumResults,
		double inWeightCost,
		double inMomentum,
		double inEWeights,
		double inESourceBias,
		double inEResultBias,
		double inErrorThreshold ){

	numResults              = inNumResults;
	weightCost 		= inWeightCost;
	momentum 		= inMomentum;
	epsilonWeights 		= inEWeights;
	epsilonSourceBias 	= inESourceBias;
	epsilonResultBias 	= inEResultBias;
	errorThreshold 		= inErrorThreshold;
	
}

/*
 * Do-nothing destructor (fill in as necessary)
 */

RBM::~RBM(){
}
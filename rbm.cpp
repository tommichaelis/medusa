#include "rbm.h"

using namespace arma;
using namespace deeplearn;
using namespace std;
using namespace rbm;

int RBM::doLearn(){
    
	mat weightIncr = zeros(numDims, numResults);
	mat sourceBiasIncr = zeros(1, numDims);
	mat resultBiasIncr = zeros(1, numResults);

	for( int iter = 0; iter < configuration->iterations; iter++ ){

        Output realOutput = stepRBM( *sourceMatrix );

        // Create some boolean hidden variables from the probabilities
        mat resultStates = sampleDistribution( realOutput.result );
		
        mat imaginedMatrix = generateProbabilityMatrix( resultStates, biases->sourceBiases, weights->t() );
        
        Output imaginedOutput = stepRBM( imaginedMatrix );
        

		weightIncr = configuration->momentum *weightIncr
						+ ( configuration->epsWeights
						* ( (realOutput.coincidence - imaginedOutput.coincidence)/numCases
							- weights*configuration->weightCost) );

		sourceBiasIncr = configuration->momentum*sourceBiasIncr
							+ ( ( configuration->epsSourceBias/numCases )
							* ( sum( *sourceMatrix ) - sum( imaginedMatrix )) );


		
		resultBiasIncr = configuration->momentum*resultBiasIncr
							+ ( ( configuration->epsResultBias/numCases )
							* (*realOutput.density - *imaginedOutput.density) );
		
		
		weights = weights + weightIncr;
		biases->sourceBiases +=  sourceBiasIncr;
		biases->resultBiases += resultBiasIncr;
	}

	return 0;
	
}


mat RBM::runForwards( mat inputMatrix ){
    return sampleDistribution( generateProbabilityMatrix( inputMatrix, biases->resultBiases, *weights ) );
}

mat RBM::runBackwards( mat inputMatrix ){
    return sampleDistribution( generateProbabilityMatrix( inputMatrix, biases->sourceBiases, weights->t() ) );
}

mat RBM::sampleDistribution( mat matrix )
{
    return ( matrix > 0.5*randn( matrix.n_rows, matrix.n_cols ) );
}

/* Do a step in an RBM, from a source level to a target level.
 *
 * matrix - is a matrix where each row is a data entry
 *
 * bias - is a vector containing biases for each hidden vector
 *
 * weights - is a matrix containing weights between the visible and 
 * hidden variables
 *
 */
Output RBM::stepRBM( mat matrix ){

    Output output;
    
	/* This generates some probabilities */
	
    output.result = generateProbabilityMatrix( matrix, biases->resultBiases, *weights );
	
	/* The following matrix contains information on the proportion of times
	 * each hidden variable is on at the same time as each visible one.
	 */
	output.coincidence = matrix.t() * output.result;
    
	/* Stores the 'onness' of hidden and visible variables on this step */
	output.density = sum( output.result );
	
 	return output;

}

Output RBM::generateProbabilityMatrix( 	
                    mat matrix,
        			mat bias,
                    mat weights 
                ){
    if( matrix.n_cols != weights.n_rows ){
        throw -1;
    }
    
    if( bias.n_cols != weights.n_cols ){
        throw -1;
    }

	/* This generates some probabilities */
	
	return 1/( 1 + exp(
						   - matrix*weights
						   - repmat( bias, matrix.n_rows, 1 )
                      )
             );
    
}

/**
 * Construct using a configuration object.
 */
RBM::RBM( Configuration config ){

    configuration = new Configuration;
    weights = new mat;
    biases = new Biases;
    
    *configuration = config;
    
    biases->resultBiases = zeros( 1, configuration->resultDimensions );
    biases->sourceBiases = zeros( 1, configuration->sourceDimensions );
    
    *weights = 0.1*randn( 
                         configuration->sourceDimensions,
                         configuration->resultDimensions 
                       );
}

RBM::~RBM(){
    delete configuration;
    delete weights;
    delete biases;
}
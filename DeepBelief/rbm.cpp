#include <DeepBelief/RBM.h>

using namespace arma;
using namespace std;
using namespace medusa;

/**
 * Construct using a configuration object.
 * 
 * @param Configuration config
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
    
    resetIncrements();
}

void RBM::resetIncrements()
{
    biases->resultBiasIncr = zeros( 1, configuration->resultDimensions );
    biases->sourceBiasIncr = zeros( 1, configuration->sourceDimensions );
    *weightIncr = zeros(
                         configuration->sourceDimensions,
                         configuration->resultDimensions 
                       );
}

/**
 * 
 * @param mat data
 * @return int
 */
int RBM::doLearn( mat data ){

	for( int iter = 0; iter < configuration->iterations; iter++ ){

        Output realOutput = stepRBM( data );

        // Create some boolean hidden variables from the probabilities
        mat resultStates = sampleDistribution( realOutput.result );
		
        mat imaginedMatrix = generateProbabilityMatrix( resultStates, biases->sourceBiases, weights->t() );
        
        Output imaginedOutput = stepRBM( imaginedMatrix );
        

		*weightIncr = configuration->momentum * (*weightIncr);
						+ ( configuration->epsWeights
						* ( (realOutput.coincidence - imaginedOutput.coincidence)/data.n_rows
							- (*weights)*configuration->weightCost) );

		biases->sourceBiasIncr = configuration->momentum*biases->sourceBiasIncr
							+ ( ( configuration->epsSourceBias/data.n_rows )
							* ( sum( data ) - sum( imaginedMatrix )) );


		
		biases->resultBiasIncr = configuration->momentum*biases->resultBiasIncr
							+ ( ( configuration->epsResultBias/data.n_rows )
							* (realOutput.density - imaginedOutput.density) );
		
		
		*weights = *weights + *weightIncr;
		biases->sourceBiases += biases->sourceBiasIncr;
		biases->resultBiases += biases->resultBiasIncr;
	}

	return 0;
	
}

/** 
 * Run the RBM forwards on a set of data, setting the visible variables to the input matrix
 * 
 * @param mat inputMatrix
 * @return mat
 */
mat RBM::runForwards( mat inputMatrix ){
    return sampleDistribution( generateProbabilityMatrix( inputMatrix, biases->resultBiases, *weights ) );
}

/**
 * Run the RBM backwards, setting the hidden variables to the input matrix
 * 
 * @param mat inputMatrix
 * @return mat
 */
mat RBM::runBackwards( mat inputMatrix ){
    return sampleDistribution( generateProbabilityMatrix( inputMatrix, biases->sourceBiases, weights->t() ) );
}

/**
 * Create a sample boolean matrix from a matrix of probabilities
 * 
 * @param mat matrix
 * @return mat
 */
mat RBM::sampleDistribution( mat matrix )
{
    umat sample = ( matrix > 0.5*randn<mat>( matrix.n_rows, matrix.n_cols ) );
    return conv_to<mat>::from(sample);
}

/** Do a step in an RBM, from a source level to a target level.
 *
 * matrix - is a matrix where each row is a data entry
 *
 * 
 * @param mat matrix
 * @return Output
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

/**
 * Generate a matrix expressing the probability of each neuron being on for a set of data
 * using weights and a bias
 * 
 * @param matrix
 * @param bias
 * @param weights
 * @return 
 */
mat RBM::generateProbabilityMatrix( 	
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

RBM::~RBM(){
    delete configuration;
    delete weights;
    delete biases;
}
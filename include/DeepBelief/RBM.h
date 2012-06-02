#ifndef RBM_H
#define	RBM_H

#include <iostream>
#include "armadillo"
#include "../ML_Layer.h"

using namespace arma;

namespace medusa {
    
    struct Biases
    {
        mat resultBiases;
        mat sourceBiases;
        
        mat resultBiasIncr;
        mat sourceBiasIncr;
    };
    
    struct Output
    {
        mat result;
        mat coincidence;
        mat density;
    };
    
    struct Configuration {

        unsigned int resultDimensions;
        unsigned int sourceDimensions;
            
        unsigned int iterations;
            
        double weightCost;
        double momentum;
        double epsWeights;
        double epsSourceBias;
        double epsResultBias;
        
    };
    
    class RBM : public ML_Layer{

            private:
                    mat * weights;
                    mat * weightIncr;

                    Configuration * configuration;
                    Biases * biases;

                    void resetIncrements();
                            
                    Output stepRBM( mat matrix );

                    mat generateProbabilityMatrix( 	
                                        mat matrix,
                                        mat bias,
                                        mat weights 
                    );

                    mat sampleDistribution( mat matrix );

            public:
                
                    int doLearn( mat data );

                    mat runForwards( mat matrix );
                    mat runBackwards( mat matrix );

                    RBM( Configuration config );
                    ~RBM();
    };

}

#endif
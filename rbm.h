#include <iostream>
#include "armadillo"

#include "component.h"

using namespace deeplearn;
using namespace arma;

namespace rbm {
    
    struct Biases
    {
        mat resultBiases;
        mat sourceBiases;
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
    
    class RBM : public Component{

            private:
                    mat * weights;

                    Configuration * configuration;
                    Biases * biases;

                    Output stepRBM( mat matrix );

                    mat generateProbabilityMatrix( 	
                                        mat matrix,
                                        mat bias,
                                        mat weights 
                    );

                    mat sampleDistribution( mat matrix );

            public:
                    int doLearn( );

                    int runForwards( mat matrix );
                    int runBackwards( mat matrix );

                    RBM( Configuration config );
                    ~RBM();
    };

}
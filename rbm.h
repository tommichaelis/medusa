#include <iostream>
#include "armadillo"

#include "component.h"

using namespace deeplearn;
using namespace arma;

namespace rbm {
    
    struct StepResults
    {
        mat hiddenMatrix;
        mat visibleMatrix;
        mat jointDensity;
        mat hiddenDensity;
        mat visibleDensity;
        
    };
    
    class Step {
        private:
            mat sourceMatrix;
            mat targetBiases;
            mat weights;
            mat jointDensityDistribution;
            mat sourceDensity;
            mat targetDensity;
            
        public:
            StepResults forwards();
            StepResults backwards();
            mat getVisible();
            mat getHidden();
        
    };
    
    class Configuration {
        private:
            unsigned int numResults;
            double weightCost;
            double momentum;
            double epsWeights;
            double epsVisibleBias;
            double epsHiddenBias;
            double iterations;
        
        public:
        
    };
    
    class RBM : public Component{

            private:
                    mat weights;
                    mat sourceBiases;
                    mat resultBiases;

                    unsigned int numCases;
                    unsigned int numDims;
                    unsigned int numResults;

                    Configuration config;

                    int stepRBM( 	mat sourceMatrix,
                                                    mat targetBiases,
                                                    mat weights,
                                                    mat * targetProbs,
                                                    mat * jointDensityMatrix,
                                                    mat * sourceDensity,
                                                    mat * targetDensity );

                    int preLearn();

            public:
                    int doLearn( );

                    int doRun( mat inputMatrix, mat *returnMatrix );

                    RBM( Configuration config );
                    ~RBM();
    };

}
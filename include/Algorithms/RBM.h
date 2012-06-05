#ifndef RBM_H
#define	RBM_H

#include <iostream>
#include "armadillo"
#include "../UnsupervisedLayer.h"

using namespace arma;

namespace medusa {

    struct RBMBiases {
        mat resultBiases;
        mat sourceBiases;

        mat resultBiasIncr;
        mat sourceBiasIncr;
    };

    struct Output {
        mat result;
        mat coincidence;
        mat density;
    };

    struct RBMConfig {
        unsigned int resultDimensions;
        unsigned int sourceDimensions;

        unsigned int iterations;

        double weightCost;
        double momentum;
        double epsWeights;
        double epsSourceBias;
        double epsResultBias;

    };

    class RBM : public UnsupervisedLayer {
    private:
        mat * weights;
        mat * weightIncr;

        RBMConfig * configuration;
        RBMBiases * biases;

        void resetIncrements();

        Output stepRBM(mat matrix);

        mat generateProbabilityMatrix(
                mat matrix,
                mat bias,
                mat weights
                );

        mat sampleDistribution(mat matrix);

    public:

        virtual int learn( mat data );
        virtual mat run( mat input );

        mat runForwards(mat matrix);
        mat runBackwards(mat matrix);
        
        virtual MatrixFormat getOutputFormat();
        virtual MatrixFormat getInputFormat();

        RBM(RBMConfig config);
        ~RBM();
    };

}

#endif
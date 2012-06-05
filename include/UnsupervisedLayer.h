
#ifndef UNSUPERVISED_LAYER_H
#define	UNSUPERVISED_LAYER_H

#include "armadillo"
#include "Layer.h"

using namespace arma;

namespace medusa {
    
    class UnsupervisedLayer : public Layer {
    private:
        Layer* nextLayer;
        Layer* previousLayer;
        
    public:
        
        virtual int learn( mat data ) = 0;
        virtual mat run( mat input ) = 0;
        
        virtual int learnIterative( mat matrix, umat classifiers );

        
    };
}

#endif


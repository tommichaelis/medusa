
#ifndef SUPERVISED_LAYER_H
#define	SUPERVISED_LAYER_H

#include "armadillo"
#include "Layer.h"

using namespace arma;

namespace Medusa {
    
    class SupervisedLayer : public Layer {
    private:
        Layer* nextLayer;
        Layer* previousLayer;
        
    public:
        
        virtual int learn( mat data, umat classifiers ) = 0;
        virtual mat run( mat input ) = 0;
        
        virtual int learnIterative( mat matrix, umat classifiers );

        
    };
}

#endif


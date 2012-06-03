
#ifndef ML_UNSUPERVISED_LAYER_H
#define	ML_UNSUPERVISED_LAYER_H

#include "armadillo"
#include "ML_Layer.h"

using namespace arma;

namespace medusa {
    
    class ML_UnsupervisedLayer : public ML_Layer {
    private:
        ML_Layer* nextLayer;
        ML_Layer* previousLayer;
        
    public:
        
        virtual int learn( mat data ) = 0;
        virtual mat run( mat input ) = 0;
        
        virtual int learnIterative( mat matrix, umat classifiers );

        
    };
}

#endif	/* ML_LAYER_H */


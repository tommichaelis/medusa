
#ifndef ML_LAYER_H
#define	ML_LAYER_H

#include "armadillo"

using namespace arma;

namespace medusa {
    
    class ML_Layer {
    private:
        ML_Layer* nextLayer;
        ML_Layer* previousLayer;
        
    public:
        
        virtual mat run( mat input ) = 0;
        
        virtual int learnIterative( mat matrix, mat classifiers ) = 0;
        mat runIterative( mat matrix );
        
        void setNextLayer( ML_Layer* next );
        void setPreviousLayer( ML_Layer* previous );

    };
}

#endif	/* ML_LAYER_H */


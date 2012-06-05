
#ifndef ML_LAYER_H
#define	ML_LAYER_H

#include "armadillo"

using namespace arma;

namespace medusa {
    
    const char * const NONE = "none";
    const char * const BOOL = "boolean";
    const char * const DOUBLE = "double";
    const char * const INT = "integer";
    
    struct MatrixFormat {
        unsigned int size;
        const char * format;
        
    };
    
    class ML_Layer {
    private:
        ML_Layer* nextLayer;
        ML_Layer* previousLayer;

        void setPreviousLayer( ML_Layer* previous );
        
    public:
        
        virtual mat run( mat input ) = 0;
        
        virtual int learnIterative( mat matrix, umat classifiers ) = 0;
        mat runIterative( mat matrix );
        
        virtual MatrixFormat getOutputFormat() = 0;
        virtual MatrixFormat getInputFormat() = 0;
        
        void setNextLayer( ML_Layer* next );

    };
}

#endif	/* ML_LAYER_H */


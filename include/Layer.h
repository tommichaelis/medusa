
#ifndef LAYER_H
#define	LAYER_H

#include "armadillo"

using namespace arma;

namespace Medusa {
    
    const char * const NONE = "none";
    const char * const BOOL = "boolean";
    const char * const DOUBLE = "double";
    const char * const INT = "integer";
    
    struct MatrixFormat {
        unsigned int size;
        const char * format;
        
    };
    
    class Layer {
    private:
        Layer* nextLayer;
        Layer* previousLayer;

        void setPreviousLayer( Layer* previous );
        
    public:
        
        virtual mat run( mat input ) = 0;
        
        virtual int learnIterative( mat matrix, umat classifiers ) = 0;
        mat runIterative( mat matrix );
        
        virtual MatrixFormat getOutputFormat() = 0;
        virtual MatrixFormat getInputFormat() = 0;
        
        void setNextLayer( Layer* next );

    };
}

#endif


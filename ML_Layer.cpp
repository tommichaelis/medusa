#include "ML_Layer.h"

using namespace medusa;


mat ML_Layer::runIterative( mat matrix )
{
    mat output = run( matrix );
    
    if( nextLayer != NULL ) {
        return nextLayer->runIterative( output );
    } else {
        return output;
    }
}

void ML_Layer::setNextLayer(ML_Layer* next) {
    nextLayer = next;
}

void ML_Layer::setPreviousLayer(ML_Layer* previous) {
    previousLayer = previous;
}


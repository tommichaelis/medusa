#include "Layer.h"
#include "string.h"
#include "Exceptions/MatrixTypeException.h"
using namespace medusa;


mat Layer::runIterative( mat matrix )
{
    mat output = run( matrix );
    
    if( nextLayer != NULL ) {
        return nextLayer->runIterative( output );
    } else {
        return output;
    }
}

void Layer::setNextLayer(Layer* next) {
    MatrixFormat nextIn = next->getInputFormat();
    MatrixFormat thisOut = getOutputFormat();
    
    if ( nextIn.format == NONE || nextIn.size != thisOut.size || strcmp( nextIn.format, thisOut.format ) != 0 ) {
        MatrixTypeException exception ("The output format of this layer does not match the input format of the next one");
        throw exception;
    }
        
    nextLayer = next;
    nextLayer->setPreviousLayer( this );
}

void Layer::setPreviousLayer(Layer* previous) {
    previousLayer = previous;
}


#include "ML_Layer.h"

using namespace medusa;


int ML_Layer::learnIterative( mat matrix )
{
    int success = learn( matrix );
    
    if( nextLayer != NULL && success == 1 ) {
        mat output = run( matrix );
        return nextLayer->learnIterative( output );
    } else {
        return success;
    }
}

int ML_Layer::runIterative( mat matrix )
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


//ML_Layer::ML_Layer() {
//}
//
//ML_Layer::ML_Layer(const ML_Layer& orig) {
//}
//
//ML_Layer::~ML_Layer() {
//}


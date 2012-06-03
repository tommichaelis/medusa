#include "ML_SupervisedLayer.h"

using namespace medusa;

int ML_SupervisedLayer::learnIterative( mat matrix, umat classifiers )
{
    int success = learn( matrix, classifiers );
    
    if( nextLayer != NULL && success == 1 ) {
        mat output = run( matrix );
        return nextLayer->learnIterative( output, classifiers );
    } else {
        return success;
    }
}


#include "UnsupervisedLayer.h"

using namespace Medusa;

int UnsupervisedLayer::learnIterative( mat matrix, umat classifiers )
{
    int success = learn( matrix );
    
    if( nextLayer != NULL && success == 1 ) {
        mat output = run( matrix );
        return nextLayer->learnIterative( output, classifiers );
    } else {
        return success;
    }
}


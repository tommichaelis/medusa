#include "SupervisedLayer.h"
#include "armadillo"
using namespace arma;
using namespace Medusa;

int SupervisedLayer::learnIterative( mat matrix, umat classifiers )
{
    int success = learn( matrix, classifiers );
    
    if( nextLayer != NULL && success == 1 ) {
        mat output = run( matrix );
        return nextLayer->learnIterative( output, classifiers );
    } else {
        return success;
    }
}


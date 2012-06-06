#include "Algorithms/SVM.h"
#include "libsvm/svm.h"
#include "armadillo"

using namespace arma;
using namespace Medusa;

SVM::SVM( ) {
}

SVM::~SVM( ) {
}

int SVM::learn( mat data, umat classifiers ) {
    
    mat classifier = classifiers.col( 0 );
    problem = new svm_problem( );
    problem->l = data.n_rows;
    problem->y = double[problem->l];
    problem->x = svm_node* [problem->l];
    for ( int iter = 0; iter < data.n_rows; iter++ ) {

        rowvec dataEntry = data.row( iter );
        ( problem->y )[iter] = classifier.row[iter];
        svm_node nodes [dataEntry.n_cols];

        int nodeNum = 0;
        for ( int colIter = 0; colIter < dataEntry.n_cols; colIter++ ) {
            double value = dataEntry.col( colIter );
            if ( value != 0 ) {
                svm_node newNode;
                newNode.index = colIter;
                newNode.value = value;
                nodes[nodeNum] = newNode;
                nodeNum++;
            }
        }
        svm_node finishNode;
        finishNode.index = -1;
        nodes[nodeNum] = finishNode;

        ( problem->x )[iter] = nodes;
    }


    return 1;
}
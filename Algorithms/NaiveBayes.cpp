#include "Algorithms/NaiveBayes.h"
#include "Exceptions/MatrixSizeException.h"

namespace medusa {

    int NaiveBayes::learn( mat data, umat classifiers ) {
        if ( data.n_rows != classifiers.n_rows ) {
            MatrixSizeException exception( "Naive Bayes: The number of data entries and classifiers do not match." );
            throw exception;
        }

        for ( int iter = 0; iter < data.n_rows; data++ ) {
        }

    }

    mat NaiveBayes::run( mat input ) {

    }

    NaiveBayes::NaiveBayes( NaiveBayesConfig config ) {
    }

    NaiveBayes::~NaiveBayes( ) {
    }

}
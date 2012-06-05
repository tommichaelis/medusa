#ifndef NAIVEBAYES_H
#define	NAIVEBAYES_H

#include "../SupervisedLayer.h"
#include "map"

using namespace std;

namespace medusa {
    
    struct GaussianDist {
        rowvec sum;
        rowvec squaredSum;
        unsigned int count;
        
        GaussianDist( int size ) {
            sum = zeros<rowvec>( size );
            squaredSum = zeros<rowvec>( size );
            count = 0;
        }
    };

    struct NaiveBayesConfig {
        unsigned int classifierColumn;
        
        unsigned int sourceDimensions;
    };

    class NaiveBayes : public SupervisedLayer {
        
    private:
        NaiveBayesConfig * configuration;
        map<unsigned int, GaussianDist* > distributions;
        GaussianDist* total;
        
        double getBayesNumerator( rowvec data, GaussianDist* dist );
        
    public:
        
        virtual int learn( mat data, umat classifiers );
        virtual mat run( mat input );
        
        virtual MatrixFormat getOutputFormat();
        virtual MatrixFormat getInputFormat();
        
        NaiveBayes( NaiveBayesConfig config );
        virtual ~NaiveBayes();
        

    };

}
#endif	/* NAIVEBAYES_H */


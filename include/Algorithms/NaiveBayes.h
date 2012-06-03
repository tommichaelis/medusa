#ifndef NAIVEBAYES_H
#define	NAIVEBAYES_H

#include "../ML_SupervisedLayer.h"


namespace medusa {
    
    struct GaussianDist {
        double sum;
        double squaredSum;
        double count;
        GaussianDist(){
            sum = 0; squaredSum = 0; count = 0;
        }
    };

    struct NaiveBayesConfig {
    };

    class NaiveBayes : public ML_SupervisedLayer {
        
    private:
        NaiveBayesConfig * configuration;
        
    public:
        
        virtual int learn( mat data, umat classifiers );
        virtual mat run( mat input );
        
        
        NaiveBayes( NaiveBayesConfig config );
        virtual ~NaiveBayes();
        

    };

}
#endif	/* NAIVEBAYES_H */


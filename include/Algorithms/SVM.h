#ifndef SVM_H
#define	SVM_H
#include "libsvm/svm.h"

#include "../SupervisedLayer.h"

namespace Medusa {

    class SVM {
    public:
        SVM();
        virtual ~SVM();
        
        virtual int learn( mat data, umat classifiers );
        virtual mat run( mat input );

    private:
        svm_model * model;
        svm_problem * problem;

    };
}

#endif	/* SVM_H */


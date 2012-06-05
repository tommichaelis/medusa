#ifndef SVM_H
#define	SVM_H

#include "../SupervisedLayer.h"

namespace Medusa {

    class SVM {
    public:
        SVM();
        virtual ~SVM();
        
        virtual int learn( mat data, umat classifiers );
        virtual mat run( mat input );

    private:

    };
}

#endif	/* SVM_H */


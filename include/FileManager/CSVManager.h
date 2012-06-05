#ifndef CSVMANAGER_H
#define	CSVMANAGER_H
#include "armadillo"
#include "../Layer.h"

using namespace arma;

namespace medusa {

    class CSVManager : public Layer {
    public:
        CSVManager( const char * filename );
        virtual ~CSVManager();
        
        virtual MatrixFormat getInputFormat();
    private:
        
        mat * LoadedMatrix;

    };
}

#endif	/* CSVMANAGER_H */


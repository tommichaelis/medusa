#ifndef CSVMANAGER_H
#define	CSVMANAGER_H
#include "armadillo"
#include "../ML_Layer.h"

using namespace arma;

namespace medusa {

    class CSVManager : public ML_Layer {
    public:
        CSVManager( const char * filename );
        virtual ~CSVManager();
        
        virtual MatrixFormat getInputFormat();
    private:
        
        mat * LoadedMatrix;

    };
}

#endif	/* CSVMANAGER_H */


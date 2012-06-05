#ifndef FILE_H
#define	FILE_H
#include "armadillo"
#include "../Layer.h"

using namespace arma;

namespace Medusa {

    class File : public Layer {
    public:
        File( const char * filename );
        virtual ~File();
        
        virtual MatrixFormat getInputFormat();
    private:
        
        mat * LoadedMatrix;

    };
}

#endif	/* CSVMANAGER_H */


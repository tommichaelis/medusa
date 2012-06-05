#include "Components/File.h"
#include "armadillo"
#include "string.h"
#include "Exceptions/FileLoadException.h"

using namespace std;

using namespace arma;
using namespace Medusa;


    
    MatrixFormat File::getInputFormat() {
        MatrixFormat format;
        format.format = NONE;
        format.size = 0;
        return format;
    }
    
    File::File( const char * cFileName ) {
        mat CSVMat;
        string fileName;
        fileName.assign( cFileName );
        if( !LoadedMatrix->load( fileName ) ) {
            FileLoadException exception ("Failed to load the CSV file");
        }
        
        *LoadedMatrix = CSVMat;
    }

    File::~File( ) {
    }
    


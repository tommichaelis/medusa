#include "FileManager/CSVManager.h"
#include "armadillo"
#include "string.h"
#include "Exceptions/FileLoadException.h"

using namespace std;

using namespace arma;

namespace medusa {

    
    MatrixFormat CSVManager::getInputFormat() {
        MatrixFormat format;
        format.format = NONE;
        format.size = 0;
        return format;
    }
    
    CSVManager::CSVManager( const char * cFileName ) {
        mat CSVMat;
        string fileName;
        fileName.assign( cFileName );
        if( !LoadedMatrix->load( fileName, csv_ascii ) ) {
            FileLoadException exception ("Failed to load the CSV file");
        }
        
        *LoadedMatrix = CSVMat;
    }

    CSVManager::~CSVManager( ) {
    }
    
}


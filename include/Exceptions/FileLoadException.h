#ifndef FILELOADEXCEPTION_H
#define	FILELOADEXCEPTION_H

#include <exception>

using namespace std;

namespace Medusa {

    class FileLoadException : public exception {
        const char* message;

        virtual const char* what() const throw () {
            return message;
        }

    public:

        FileLoadException(const char* input = "Failed to load the file") {
            message = input;
        }

    };
}

#endif	/* MATRIXSIZEEXCEPTION_H */


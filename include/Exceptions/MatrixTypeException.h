#ifndef MATRIXTYPEEXCEPTION_H
#define	MATRIXTYPEEXCEPTION_H

#include <exception>

using namespace std;

namespace Medusa {

    class MatrixTypeException : public exception {
        const char* message;

        virtual const char* what() const throw () {
            return message;
        }

    public:

        MatrixTypeException(const char* input = "The format of your matrices did not match") {
            message = input;
        }

    };

}
#endif	/* MATRIXSIZEEXCEPTION_H */


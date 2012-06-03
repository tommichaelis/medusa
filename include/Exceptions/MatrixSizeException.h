#ifndef MATRIXSIZEEXCEPTION_H
#define	MATRIXSIZEEXCEPTION_H

#include <exception>

using namespace std;

class MatrixSizeException : public exception {
    
    const char* message;
    
    virtual const char* what() const throw() {
        return message;
    }
    
public:
    MatrixSizeException( const char* input = "The dimensions of your matrices did not match" ){
        message = input;
    }
    
};

#endif	/* MATRIXSIZEEXCEPTION_H */


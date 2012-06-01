#include "component.h"

using namespace deeplearn;


int Component::setSourceMatrix( mat* inputSource ){
	if(NULL == inputSource){
		return -1;
	}

	sourceMatrix = inputSource;
	return 0;
}

int Component::connectComponent( Component * nextComponent ){
	int err = nextComponent -> setSourceMatrix( targetMatrix );
	nextStep = nextComponent;
	return err;
}

int Component::learn(){
	int err = doLearn();
	if( 0 > err ){
		return err;
	}
	
//	return nextStep -> learn();
}

int Component::run( mat inputMatrix ){
	mat * newMatrix = new mat();
	int err = doRun( inputMatrix, newMatrix );
	cout << *newMatrix << endl;
	if( 0 > err ){
		return err;
	}
	
//	return nextStep->run( *newMatrix );
}

mat Component::getTarget(){
	return *targetMatrix;
}
	


#include <iostream>
#include "armadillo"

using namespace arma;

namespace deeplearn {
	class Component {

		protected:
			mat * sourceMatrix;
			mat * resultMatrix;
            
			Component * nextStep;
			
			
			virtual int doLearn() = 0;
			virtual int doRun( mat inputMatrix, mat * returnMatrix) = 0;

		public:
			int setSourceMatrix ( mat * inputSource );
			int connectComponent ( Component * nextComponent );
			int learn();
		
			int run( mat inputMatrix );
			mat getTarget();

	};
}
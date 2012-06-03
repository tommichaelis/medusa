
#ifndef ML_LAYER_H
#define	ML_LAYER_H

namespace medusa {
    
    class ML_Layer {
    private:
        ML_Layer* nextLayer = NULL;
        ML_Layer* previousLayer = NULL;
        
    public:
        
        virtual int learn( mat data ) = 0;
        virtual int run( mat input ) = 0;
        
        int learnIterative( mat matrix );
        mat runIterative( mat matrix );
        
        void setNextLayer( ML_Layer* next );
        void setPreviousLayer( ML_Layer* previous );

    };
}

#endif	/* ML_LAYER_H */


//
//  ofBall.h
//  Balls
//
//  Created by Antti Onttonen on 06/03/15.
//
//

#ifndef __Balls__ofBall__
#define __Balls__ofBall__

#include "ofMain.h"

class ofBall {

public:
    
    // methods
    void update();
    void draw();

    // variables
    float x;
    float y;
    float speedX;
    float speedY;
    int dim;
    
    // constructor
    ofBall(float x, float y, int dim);
    
private:

};

#endif /* defined(__Balls__ofBall__) */

//
//  Atom.hpp
//  AppD
//
//  Created by Antti Onttonen on 08/08/2017.
//

#ifndef _ATOM
#define _ATOM

#include "ofMain.h"

class Atom {
    
public:
    
    void setup(float _x, float _y, float _angleBegin, float _angleEnd);
    void update(float _radius);
    void draw();
    
    float x;
    float y;
    
    float outerRadius;
    float innerRadius;
    
    float angleBegin;
    float angleEnd;
    
    Atom();
    
private:
    
};

#endif

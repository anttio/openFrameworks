//
//  Emblem.hpp
//  AppD
//
//  Created by Antti Onttonen on 16/08/2017.
//

#ifndef _EMBLEM
#define _EMBLEM

#include "ofMain.h"

class Emblem {
    
public:
    
    void setup(float _x, float _y, float _rotate);
    void update(float _rotate);
    void draw();
    
    float x;
    float y;
    float rotate;
    
    ofImage emblem_outer;
    ofImage emblem_inner;
    
private:
    
};

#endif

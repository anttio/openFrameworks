//
//  Atom.cpp
//  AppD
//
//  Created by Antti Onttonen on 08/08/2017.
//

#include "Atom.h"

Atom::Atom(){
    
}

void Atom::setup(float _x, float _y, float _angleBegin, float _angleEnd){
    
    x = _x;
    y = _y;
    
    outerRadius = 50;
    innerRadius = 26;
    
    angleBegin = _angleBegin;
    angleEnd = _angleEnd;
    
}

void Atom::update(float _radius){
    
    angleEnd += _radius;
    angleBegin += _radius;
    
}

void Atom::draw(){
    
    ofPath p;
    
    p.arc(x, y, outerRadius, outerRadius, angleBegin, angleEnd);
    p.arcNegative(x, y, innerRadius, innerRadius, angleEnd, angleBegin);
    p.close();
    
    p.setCircleResolution(100);
    
    ofColor c(26, 33, 43);
    p.setFillColor(c);
    
    p.draw();
    
}

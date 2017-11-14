//
//  Emblem.cpp
//  AppD
//
//  Created by Antti Onttonen on 16/08/2017.
//

#include "Emblem.h"

void Emblem::setup(float _x, float _y, float _rotate)
{
    x = _x;
    y = _y;
    rotate = _rotate;
    
    rotate = 0;
    
    emblem_outer.load("emblem_outer.png");
    emblem_inner.load("emblem_inner.png");
}

void Emblem::update(float _rotate)
{
    rotate += _rotate * 0.05;
}

void Emblem::draw()
{
    ofPushMatrix();
    
        ofTranslate(emblem_outer.getWidth() / 2 + x, emblem_outer.getHeight() / 2 + y);
    
        ofPushMatrix();
        ofRotate(ofGetFrameNum() * -rotate, 0, 0, 1);
        emblem_outer.draw(-emblem_outer.getWidth() / 2, -emblem_outer.getHeight() / 2);
        ofPopMatrix();
    
        ofPushMatrix();
        ofRotate(ofGetFrameNum() * rotate, 0, 0, 1);
        emblem_inner.draw(-emblem_inner.getWidth() / 2, -emblem_inner.getHeight() / 2);
        ofPopMatrix();
    
    ofPopMatrix();
}

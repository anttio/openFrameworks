//
//  ofBall.cpp
//  Balls
//
//  Created by Antti Onttonen on 06/03/15.
//
//

#include "ofBall.h"

ofBall::ofBall(float _x, float _y, int _dim){
    x = _x;
    y = _y;
    dim = _dim;

    speedX = ofRandom(-1, 1);
    speedY = ofRandom(-1, 1);
}

void ofBall::update(){
    if (x < 0) {
        x = 0;
        speedX *= -1;
    } else if (x > ofGetWidth()) {
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if (y < 0) {
        y = 0;
        speedY *= -1;
    } else if (y > ofGetHeight()) {
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x += speedX;
    y += speedY;
}

void ofBall::draw(){
    ofSetColor(120, 120, 120);
    ofCircle(x, y, dim);
}
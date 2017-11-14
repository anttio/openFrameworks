//
//  CustomParticle.h
//  LotteryMachine
//
//  Created by Antti Onttonen on 19/05/15.
//
//

#ifndef LotteryMachine_CustomParticle_h
#define LotteryMachine_CustomParticle_h

#include <string>

class ParticleData {

public:
    
    int id;
    int type; // 0 = Circle, 1 = Slot
    bool bHit;
    int hitById;
    bool isActive;
    
};

// Extend the Box2dCircle
class CustomParticle : public ofxBox2dCircle {
    
public:
    
    void draw() {
        
        ParticleData* pd = (ParticleData*)getData();
        
        if (pd) {
            float radius = getRadius();
            
            ofPushMatrix();
            
            ofTranslate(getPosition());
            ofRotateZ(getRotation());
            
            // Is waiting for a hit
            if (pd->isActive) {
                ofSetColor(0, 169, 224);
            }

            // Has been hit
            if (pd->isActive && pd->bHit && pd->type == 1) {
                ofSetColor(152, 199, 61);
            }
            
            ofCircle(0, 0, radius);
            
            float textSize = radius / 15;

            ofPushMatrix();
            
            ofScale(textSize, textSize);
            ofSetColor(255);
            
            if (pd->isActive && pd->type == 1 && pd->hitById != 0) {
                ofDrawBitmapString(ofToString(pd->hitById), -6, 4);
            }
            
            ofPopMatrix();
            
            ofPopMatrix();
        }

    }
    
};

#endif

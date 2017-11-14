#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"

#include "ofxBox2d.h"

#include "CustomParticle.h"

#define CIRCLES 39
#define CIRCLE_RADIUS 22

#define SLOTS 7
#define SLOT_RADIUS 26

class ofApp : public ofxiOSApp {
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
        void contactStart(ofxBox2dContactArgs &e);
        void contactEnd(ofxBox2dContactArgs &e);

    ofSoundPlayer  sound[1];
    
    ofxBox2d box2d;
    ofxBox2dCircle anchor;

    vector <shared_ptr<ofxBox2dCircle> > circles;
    vector <shared_ptr<ofxBox2dCircle> > slots;
    vector <shared_ptr<ofxBox2dJoint> > joints;
    
    int collisions, winterval;
    
    bool showJoints, soundForEveryHit;
    
};

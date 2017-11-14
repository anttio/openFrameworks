#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    showJoints = false; // Show joint balls in top of screen
    soundForEveryHit = false; // Make sounds from more hits. Making everything slower.
    
    // Environment
    ofSetVerticalSync(true);
    ofBackground(59, 59, 61);
    interval = 0;
    
    // Use accelerometer
    ofxAccelerometer.setup();
    
    // Setup Box2d
    box2d.init();
    box2d.enableEvents();
    box2d.setGravity(0, 10);
    box2d.createBounds();
    box2d.setIterations(8, 3);
    box2d.setFPS(60.0);
    box2d.registerGrabbing();
    
    // Register event listeners
    ofAddListener(box2d.contactStartEvents, this, &ofApp::contactStart);
    ofAddListener(box2d.contactEndEvents, this, &ofApp::contactEnd);
    collisions = 0;
    
    // Floating circles
    for (int i = 0; i < CIRCLES; i++) {
        shared_ptr<CustomParticle> circle = shared_ptr<CustomParticle>(new CustomParticle);

        // Setup circle physics, initial position and size
        circle.get()->setPhysics(2, 0.4, 0.1);
        circle.get()->setup(box2d.getWorld(), ofRandomWidth(), ofRandomHeight(), CIRCLE_RADIUS);
        circle.get()->setVelocity(ofRandom(-4, 4), ofRandom(-3, 3));
        
        // Setup circle data
        circle.get()->setData(new ParticleData());
        ParticleData* pd = (ParticleData*)circle.get()->getData();
        pd->id = i;
        pd->type = 0;
        pd->bHit = false;
        
        circles.push_back(circle);
    }
    
    // Empty slots
    for (int i = 0; i < SLOTS; i++) {
        shared_ptr<CustomParticle> slot = shared_ptr<CustomParticle>(new CustomParticle);
        
        // Setup slot physics, position and size
        slot.get()->setPhysics(0, 1, 0);
        slot.get()->setup(box2d.getWorld(), ofGetWidth() / 2, ((ofGetHeight() - SLOT_RADIUS * SLOTS) / (SLOTS + 1) * (i + 2)) - SLOT_RADIUS / 2, SLOT_RADIUS);

        // Setup slot data
        slot.get()->setData(new ParticleData());
        ParticleData* pd = (ParticleData*)slot.get()->getData();
        pd->id = i;
        pd->type = 1;
        pd->bHit = false;
        pd->isActive = false;
        
        slots.push_back(slot);
    }
    
    // Load sounds
    sound[0].loadSound("1.mp3");
    sound[0].setLoop(false);

    // Joints
    if (showJoints) {
        anchor.setup(box2d.getWorld(), ofGetWidth() / 2, 20, 10);
        for (int i = 0; i < SLOTS; i++) {
            shared_ptr<ofxBox2dJoint> joint = shared_ptr<ofxBox2dJoint>(new ofxBox2dJoint);
        
            // if this is the first point connect to the top anchor.
            if(i == 0) {
                joint.get()->setup(box2d.getWorld(), anchor.body, circles[i].get()->body);
            } else {
                joint.get()->setup(box2d.getWorld(), circles[i-1].get()->body, circles[i].get()->body);
            }
        
            joint.get()->setLength(25);
            joints.push_back(joint);
        }
    }
}

//--------------------------------------------------------------
void ofApp::contactStart(ofxBox2dContactArgs &e){
    
    if (e.a != NULL && e.b != NULL) {
        if (e.a->GetType() == b2Shape::e_circle && e.b->GetType() == b2Shape::e_circle) {
            
            ParticleData* aData = (ParticleData*)e.a->GetBody()->GetUserData();
            ParticleData* bData = (ParticleData*)e.b->GetBody()->GetUserData();

            if (aData && bData) {

                // If circle 0 and slot 1 collide
                if (aData->type == 0 && bData->type == 1) {

                    // Only if slot hasn’t been hit
                    if (!bData->bHit && bData->isActive) {
                        collisions++;

                        // Update drawn numbers
                        if (!aData->bHit) {
                            bData->hitById = aData->id;

                            aData->bHit = true;
                            bData->bHit = true;
                            
                            // Joints TODO: Not working
//                            shared_ptr<ofxBox2dJoint> joint = shared_ptr<ofxBox2dJoint>(new ofxBox2dJoint);
//                            joint.get()->setup(box2d.getWorld(), e.a->GetBody(), e.b->GetBody());
//                            joint.get()->setLength(25);
//                            joints.push_back(joint);
                        }
                        
                        sound[0].play();
                    }

                    if (soundForEveryHit) {
                        sound[0].play(); // slows down
                    }
                }

            }
            
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::contactEnd(ofxBox2dContactArgs &e){
//    sound[0].stop();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    interval++;

    if (interval % 60 == 0) {
        ParticleData* pd = (ParticleData*)slots[ofRandom(0, SLOTS)].get()->getData();
        pd->isActive = true;

//        printf("%i", interval);
    }
    
    // Update the world
    ofVec2f gravity = ofxAccelerometer.getForce();
    gravity.y *= -1;
    gravity *= 30;
    box2d.setGravity(gravity);
    
    box2d.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    // Floating circles
    for (int i = 0; i < circles.size(); i++) {
        ofFill();
        ofSetColor(208, 221, 43);
        circles[i].get()->draw();
    }

    // Empty slots
    for (int i = 0; i < slots.size(); i++) {
        ofFill();
        ofSetColor(103, 205, 220);
        slots[i].get()->draw();
    }
    
    if (showJoints) {
        anchor.draw();
        for(int i = 0; i < joints.size(); i++) {
            ofSetHexColor(0x444342);
            joints[i].get()->draw();
        }
    }
    
    // DEBUG INFO
    string info = "";
    info += "FPS: " + ofToString(ofGetFrameRate(), 1) + "\n";
    info += "COLLISIONS: " + ofToString(collisions) + "\n";
    ofSetColor(0, 169, 224);
    ofDrawBitmapString(info, 30, 30);
    
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}

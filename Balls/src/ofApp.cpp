#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(30);
    
    ofEnableSmoothing();
    ofNoFill();
    
    nBalls = 5;
    
    myBall = new ofBall * [nBalls];
    
    for (int i = 0; i < nBalls; i++) {
        float x = 20 + (100 * i);
        float y = 20 + (100 * i);
        int dim = 10 + (i * 10);
        
        myBall[i] = new ofBall(x, y, dim);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < nBalls; i++) {
        myBall[i]->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < nBalls; i++) {
        myBall[i]->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

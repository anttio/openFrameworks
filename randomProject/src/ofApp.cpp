#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    nTri = 1500;
    nVert = nTri * 3;
    
    float Rad = 250;
    float rad = 25;
    
    vertices.resize(nVert);
    
    for (int i = 0; i < nTri; i++) {
        ofPoint center(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
        center.normalize();
        center *= Rad;
        
        for (int j = 0; j < 3; j++) {
            vertices[i * 3 + j] = center + ofPoint(ofRandom(-rad, rad), ofRandom(-rad, rad), ofRandom(-rad, rad));
        }
    }
    
    colors.resize(nTri);
    
    for (int i = 0; i < nTri; i++) {
        colors[i] = ofColor(ofRandom(0, 255), 0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    
    ofBackgroundGradient(ofColor(255), ofColor(128));
    
    ofPushMatrix();
    
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    float time = ofGetElapsedTimef();
    float angle = time * 10;
    ofRotate(angle, 0, 1, 0);
    
    for (int i = 0; i < nTri; i++) {
        ofSetColor(colors[i]);
        ofDrawTriangle(vertices[i * 3], vertices[i * 3 + 1], vertices[i * 3 + 2]);
    }
    
    ofPopMatrix();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

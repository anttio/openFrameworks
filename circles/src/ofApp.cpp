#include "ofApp.h"
#include "Atom.h"
#include "Emblem.h"

#define ROWS 11
#define COLS 20
vector <Atom> electrons;
vector <Emblem> emblems;

float scale = 0.53;
//int translateX = 150;
//int translateY = 125;
int translateX = 100;
int translateY = 55;

//--------------------------------------------------------------
void ofApp::setup(){
    
    int electronSpace = 110;
    int emblemSpace = 280;
    
//    gui.setup();
//    gui.add(radius.setup("radius", 360, 0, 360));
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Atom electron;
            electron.setup(j * electronSpace, i * electronSpace, 0, int(ofRandom(0, 360)));
            electrons.push_back(electron);
            
            Emblem emblem;
            emblem.setup(j * emblemSpace, i * emblemSpace, ofRandom(0, 5));
            emblems.push_back(emblem);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < emblems.size(); i++) {
        emblems[i].update(.25);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255, 255, 255);
    
//    gui.draw();
    
    ofPushMatrix();
    
    ofScale(scale, scale);
    ofTranslate(translateX, translateY);
    
    for (int i = 0; i < electrons.size(); i++) {
//        electrons[i].draw();
        emblems[i].draw();
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
    
//    for (int i = 0; i < electrons.size(); i++) {
//        float distance = ofDist(x, y, (electrons[i].x + translateX) * scale, (electrons[i].y + translateY) * scale);
//
//        if (distance < electrons[i].outerRadius) {
//            electrons[i].update(25);
//        }
//    }
    
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


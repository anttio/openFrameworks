#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Load images
    string path = "images";
    ofDirectory dir(path);
    dir.allowExt("jpg");
    dir.listDir();

    imageSize = ofGetHeight() / 4;
    
    for (int i = 0; i < dir.size(); i++) {
        ofImage image;
        image.load(dir.getPath(i));
        images.push_back(image);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBox(10, 10, 10, 100, 100, 100);
    
    
    
    int cols = ceil(ofGetWidth() / imageSize);
    int rows = ceil(ofGetHeight() / imageSize);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i * cols + j < images.size()) {
                
//                ofPushMatrix();
//                ofRotate(10,0,0,1.0);

//                images[i * cols + j].draw(imageSize * j, imageSize * i, imageSize, imageSize);
//                ofPopMatrix();
            }
        }
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

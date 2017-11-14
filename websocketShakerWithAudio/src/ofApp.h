#pragma once

#include "ofMain.h"
#include "ofxLibwebsockets.h"
#include "ofxMaxim.h"

#define NUM_MESSAGES 30 // how many past messages we want to keep

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxLibwebsockets::Server server;

    bool debug;
    bool bSetup;

    // WEBSOCKETS
    vector<string> messages;
    void onConnect(ofxLibwebsockets::Event& args);
    void onOpen(ofxLibwebsockets::Event& args);
    void onClose(ofxLibwebsockets::Event& args);
    void onIdle(ofxLibwebsockets::Event& args);
    void onMessage(ofxLibwebsockets::Event& args);
    void onBroadcast(ofxLibwebsockets::Event& args);

    // GRAPHICS
    vector<ofPoint> vertices;
    vector<ofColor> colors;
    
    int nTri;
    int nVert;
    int spheres;
    
    float rotation;
    float scaleX, scaleY, scaleZ;

    // AUDIO
    void audioOut(float * output, int bufferSize, int nChannels);
    int bufferSize;
    int sampleRate;
    ofxMaxiOsc mySine, myOtherSine;
};
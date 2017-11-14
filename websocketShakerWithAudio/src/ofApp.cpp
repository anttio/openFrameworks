#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    debug = false;
    
    // WEBSOCKETS
    ofxLibwebsockets::ServerOptions options = ofxLibwebsockets::defaultServerOptions();
    options.port = 9092;
    options.bUseSSL = false;
    bSetup = server.setup(options);
    
    server.addListener(this);
    
    // GRAPHICS
    // Example from rMastering openFrameworks: Creative Coding Demystified Ð Denis Perevalov
    ofSetFrameRate(60);
    
    nTri = 1500;
    nVert = nTri * 3;
    spheres = 1;
    
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
        colors[i] = ofColor(ofRandom(0, 255), ofRandom(0, 128), ofRandom(0, 255), 90);
    }
    
    scaleX = 1.0;
    scaleY = 1.0;
    scaleZ = 1.0;
    
    // AUDIO
    sampleRate = 44100;
    bufferSize = 512;
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    ofSoundStreamSetup(2, 2, this, sampleRate, bufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (debug) {
        if (bSetup){
            ofDrawBitmapString("WebSocket server setup at " + ofToString(server.getPort()) + (server.usingSSL() ? " with SSL" : " without SSL"), 20, 20);
            ofSetColor(150);
        } else {
            ofDrawBitmapString("WebSocket setup failed", 20, 20);
        }
        
        int x = 20;
        int y = 100;
        
        ofSetColor(0, 150, 0);
        ofDrawBitmapString("Console", x, 80);
        
        ofSetColor(255);
        for (int i = messages.size() -1; i >= 0; i--){
            ofDrawBitmapString(messages[i], x, y);
            y += 20;
        }
        if (messages.size() > NUM_MESSAGES) messages.erase(messages.begin());
    }
    
    
    ofEnableDepthTest();
    
    ofBackground(rotation * 40, 0, rotation * 20);
    
    for (int i = 1; i < spheres + 1; i++) {
        ofPushMatrix();

        // TODO: Random locations without sphere limitation
        if (i == 1) ofTranslate((ofGetWidth() / 2), ofGetHeight() / 2);
        if (i == 2) ofTranslate((ofGetWidth() / 2 - 300), ofGetHeight() / 2);
        if (i == 3) ofTranslate((ofGetWidth() / 2 + 300), ofGetHeight() / 2);
    
        float time = ofGetElapsedTimef();
        float angle = time * -10;
    
        ofRotate(angle, 0, 1, 0);
        ofScale(scaleX, scaleY, scaleZ);

        for (int i = 0; i < nTri; i++) {
            ofSetColor(colors[i]);
            ofDrawTriangle(vertices[i * 3] * rotation,
                           vertices[i * 3 + 1] * rotation,
                           vertices[i * 3 + 2] * rotation);
        }

        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::onConnect( ofxLibwebsockets::Event& args ){
    cout<<"on connected"<<endl;
}

//--------------------------------------------------------------
void ofApp::onOpen( ofxLibwebsockets::Event& args ){
    cout<<"new connection open"<<endl;
    messages.push_back("New connection from " + args.conn.getClientIP() + ", " + args.conn.getClientName());
}

//--------------------------------------------------------------
void ofApp::onClose( ofxLibwebsockets::Event& args ){
    cout<<"on close"<<endl;
    messages.push_back("Connection closed");
}

//--------------------------------------------------------------
void ofApp::onIdle( ofxLibwebsockets::Event& args ){
    cout<<"on idle"<<endl;
}

//--------------------------------------------------------------
void ofApp::onMessage( ofxLibwebsockets::Event& args ){
    cout<<"message "<<args.message<<endl;
    
    // trace out string messages or JSON messages!
    if ( !args.json.isNull() ){
        messages.push_back(args.json.toStyledString());
        
        int beta = ofToInt(args.json["beta"].asString());
        int gamma = ofToInt(args.json["gamma"].asString());
        int alpha = ofToInt(args.json["alpha"].asString());
        
        scaleX = ofMap(gamma, -90, 90, -0.5, 1.5);  // gamma min & max: -90, 90
        scaleY = ofMap(beta, -180, 180, -0.5, 1.5); // beta min & max: -180, 180
        scaleZ = 1;                                 // alpha min & max: 0, 360

        rotation = ofMap(alpha, 0, 360, 0, 10);
    } else {
        if (spheres < 3) {
            spheres++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::onBroadcast( ofxLibwebsockets::Event& args ){
    cout<<"got broadcast "<<args.message<<endl;
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    for (int i = 0; i < bufferSize; i++) {
        output[i*nChannels] = mySine.sinewave(440 * rotation) + myOtherSine.sinewave(441 * rotation);
        output[i*nChannels + 1] = mySine.sinewave(450 * rotation) + myOtherSine.sinewave(451 * rotation);
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
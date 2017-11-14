#include "ofMain.h"
#include "ofApp.h"

int main(){
    
    ofAppiOSWindow * iOSWindow = new ofAppiOSWindow;
    iOSWindow->enableAntiAliasing(4);
    iOSWindow->enableRetina();
    
    ofSetupOpenGL(1024,768,OF_FULLSCREEN);			// <-------- setup the GL context
    ofRunApp(new ofApp());
    
}

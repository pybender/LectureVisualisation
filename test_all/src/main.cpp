#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

int main() { 
    ofGLFWWindowSettings settings;
    settings.width = 1920;
    settings.height = 1080;
    settings.setPosition(ofVec2f(500,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
//    mainWindow->setFullscreen(true);

    settings.width = 500;
    settings.height = ofGetScreenHeight();
    settings.setPosition(ofVec2f(0,0));
    settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setupGui();
    ofAddListener(guiWindow->events().draw, mainApp.get(), &ofApp::drawGui);
    ofAddListener(guiWindow->events().keyPressed, mainApp.get(), &ofApp::guiKeyPressed);
    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}

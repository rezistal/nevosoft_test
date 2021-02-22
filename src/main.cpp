#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
	settings.setSize(800, 600);
	settings.setPosition(glm::vec2(400, 100));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	shared_ptr<ofApp> mainApp(new ofApp());
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}

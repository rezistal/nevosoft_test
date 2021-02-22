#include "GuiApp.h"

GuiApp::GuiApp() {

}

void GuiApp::setup(){
	gui.setup("Options", "settings.xml", 20, 70);
	gui.add(auto_fireworks.setup("Auto Fireworks", true));
	gui.add(fps_label.setup("FPS", ""));
	//gui.add(pause.setup("Pause", 200.0f));
}

void GuiApp::update(){
	fps_label.setup("FPS", to_string((int)ofGetFrameRate()));
}

void GuiApp::draw(){
	gui.draw();
}

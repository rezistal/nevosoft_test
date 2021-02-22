#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class GuiApp {

	public:
		void setup();
		void update();
		void draw();

		ofxLabel fps_label;
		ofxToggle auto_fireworks;
		ofxFloatSlider slider;
		ofxGuiGroup gui;

		GuiApp();

};


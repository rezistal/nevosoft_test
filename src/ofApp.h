#pragma once

#include "ofMain.h"
#include "Firework.h"
#include "Parameter.h"
#include "Button.h"

class ofApp : public ofBaseApp{
	public:
		ofImage img_button_up;
		ofImage img_button_up_pressed;
		ofImage img_button_down;
		ofImage img_button_down_pressed;
		ofImage img_button_pause;
		ofImage img_button_pause_pressed;

		ofImage img_pause_menu;

		int param_particles_in_firework;
		Button inc_particles_in_firework;
		Button dec_particles_in_firework;
		
		int param_pause;
		Button pause;
		Button pause_pressed;

		int param_gravity;
		Button inc_gravity;
		Button dec_gravity;

		vector<Firework> fireworks;

		ofApp();

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		bool isGamePaused();
		
};

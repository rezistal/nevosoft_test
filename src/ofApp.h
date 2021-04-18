#pragma once

#include "ofMain.h"
#include "Firework.h"
#include "Parameter.h"
#include "Button.h"

class ofApp : public ofBaseApp{
	private:
		int app_param_pause;
		int app_param_exit;
		int app_param_click_detector;

		int app_param_fireworks_count;
		int app_param_particles_count;

	
		ofImage img_button_up;
		ofImage img_button_up_pressed;
		ofImage img_button_down;
		ofImage img_button_down_pressed;
		ofImage img_button_pause;
		ofImage img_button_pause_pressed;

		ofImage img_pause_menu;
		ofImage img_button_resume;
		ofImage img_button_exit;

		ofImage img_sky;
		ofImage img_window;
		ofImage img_window_light;

		int param_particles_in_firework;
		int param_gravity;
		int param_slow;

		Button buttons_layer0[7];
		Button buttons_layer1[2];
		vector<Firework> fireworks;

		//Стрелять 1 раз в global_timer секунд
		float global_timer;
		//Время timeDelta от 0 до global_timer
		float timeDelta;

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

		bool GamePaused();

	public:
		ofApp();
};

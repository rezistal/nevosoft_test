#include "ofApp.h"

float chance;
float increase_chance = 0;
int fireworks_count = 0;
int particles_count = 0;

ofImage img1;
ofImage img2;
ofImage *img_todraw;


Parameter<int> ptest;
Parameter<int> ptest2;

ofApp::ofApp() {

}

//--------------------------------------------------------------
void ofApp::setup(){
	img_button_up.loadImage("button_up.png");
	img_button_up_pressed.loadImage("button_up_pressed.png");
	img_button_down.loadImage("button_down.png");
	img_button_down_pressed.loadImage("button_down_pressed.png");
	img_button_pause.loadImage("pause.png");
	img_button_pause_pressed.loadImage("pause_pressed.png");


	this->inc_particles_in_firework = Button(&img_button_up, &img_button_down_pressed, 20, 60, Parameter<int>(&this->param_particles_in_firework, 1, 1, 1, 1, 1000));
	this->dec_particles_in_firework = Button(&img_button_down, &img_button_down_pressed, 20, 90, Parameter<int>(&this->param_particles_in_firework, 1, -1, 1, 1, 1000));
	this->pause = Button(&img_button_pause, &img_button_pause_pressed, 20, 200, Parameter<int>(&this->param_pause, 0, 0, -1, -1, 1));

	img1.loadImage("cat.png");
	img2.loadImage("cat2.png");
	img_todraw = &img1;
	this->param_pause = 1;
	ofSetFrameRate(120);
	ofSetWindowTitle("Nevosoft fireworks!");
	ofBackground(0, 0, 0);
	//ofSetBackgroundAuto(false);
	//ofEnableAlphaBlending();
	//ofSetLineWidth(2);
	gravity = ofVec2f(0, 0.05f);

}

//--------------------------------------------------------------
void ofApp::update(){

	if (this->param_pause == 1) {
		int s = fireworks.size();
		particles_count += s;
		for (int i = s - 1; i >= 0; i--) {
			fireworks.at(i).Update();
			if (fireworks.at(i).done) {
				fireworks.erase(fireworks.begin() + i);
			}
		}
		if (true) {
			chance = ofRandom(0, 1000) + increase_chance;
			if (chance > 999) {
				increase_chance = 0;
				int x = ofRandom(100, ofGetWindowWidth() - 100);
				int y = ofRandom(100, ofGetWindowHeight() - 100);

				Firework f = Firework(x, y);
				f.particles_amount = this->param_particles_in_firework;
				f.Init_particles();

				fireworks.push_back(f);
				particles_count += f.particles_amount;
				fireworks_count += 1;

			}
			else {
				increase_chance += 1;
			}
		}

	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	int s = fireworks.size();
	
	for (int i = 0; i < s; i++) {
		int sz = fireworks.at(i).particles.size();
		Particle *p;
		for (int j = 0; j < sz; j++) {
			p = &fireworks.at(i).particles.at(j);
			p->draw();
			//ofSetColor(p->red, p->green, p->blue , p->transparency);
			//ofCircle(p->position.x, p->position.y, 5);
		}
	}

	ofSetColor(255, 255, 255);
	std::stringstream strm;
	strm << "FPS: " << ofGetFrameRate() << endl;
	strm << "Current cnt: " << s << endl;
	strm << "Total fireworks cnt: " << fireworks_count << endl;
	strm << "Total particles cnt: " << particles_count << endl;
	ofDrawBitmapString(strm.str(), 20, 20);
	ofDrawBitmapString(this->param_particles_in_firework, 20, 40);
	//img_todraw->draw(200, 200);

	this->inc_particles_in_firework.Draw();
	this->dec_particles_in_firework.Draw();
	this->pause.Draw();
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
	/*
	int param_size = params.size();
	for (int i = 0; i < param_size; i++) {
		params.at(i)->Test();
	}

	if (this->inc_min_particles.Inside(x, y)) {
		//this->min_particles++;
	}

	if (this->dec_min_particles.Inside(x, y)) {
		//this->min_particles--;
	}
	*/
	this->inc_particles_in_firework.Click(x,y);
	this->dec_particles_in_firework.Click(x,y);
	this->pause.Click(x,y);

	if (x >= 200 && x <= 200 + img_todraw->getWidth()
		&& y >= 200 && y <= 200 + img_todraw->getHeight()) {
		img_todraw = &img2;
	}
	else {
		img_todraw = &img1;
	}
	/*
	if (pause == 1) {
		Firework f = Firework(x, y);
		fireworks.push_back(f);
		particles_count += f.particles_amount;
		fireworks_count += 1;
	}*/
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	this->inc_particles_in_firework.Click_released(x, y);
	this->dec_particles_in_firework.Click_released(x, y);
	this->pause.Click_released(x, y);
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

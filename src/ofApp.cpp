#include "ofApp.h"
#include "Firework.h"
#include "GuiApp.h"

float chance;
float increase_chance = 0;
int fireworks_count = 0;
int particles_count = 0;


//Particle p;
//ofVec2f counter_force;

//vector<int>::iterator the_iterator;

//--------------------------------------------------------------
void ofApp::setup(){

	this->gui.setup();

	pause = 1;
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
	this->gui.update();

	if (pause == 1) {
		int s = fireworks.size();
		particles_count += s;
		for (int i = s - 1; i >= 0; i--) {
			fireworks.at(i).Update();
			if (fireworks.at(i).done) {
				fireworks.erase(fireworks.begin() + i);
			}
		}
		if (this->gui.auto_fireworks) {
			chance = ofRandom(0, 1000) + increase_chance;
			if (chance > 999) {
				increase_chance = 0;
				int x = ofRandom(100, ofGetWindowWidth() - 100);
				int y = ofRandom(100, ofGetWindowHeight() - 100);

				fireworks.push_back(Firework(x, y));
				fireworks_count += 1;

			}
			else {
				increase_chance += 1;
			}
		}

	}
	//p.ApplyForce(gravity);
	//p.velocity += p.acceleration + gravity;
	//p.position += p.velocity;
	//p.acceleration *= 0;
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->gui.draw();

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
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// k для теста
	if (key = 107) {
		pause *= -1;
	}
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
	if (pause == 1) {
		Firework f = Firework(x, y);
		fireworks.push_back(f);
		particles_count += f.particles.size();
		fireworks_count += 1;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

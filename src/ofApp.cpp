#include "ofApp.h"
#include "Particle.h"
#include "Firework.h"
float chance;
float increase_chance = 0;
//Particle p;
//ofVec2f counter_force;

//vector<int>::iterator the_iterator;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	//ofSetBackgroundAuto(false);
	//ofEnableAlphaBlending();
	gravity = ofVec2f(0, 0.05f);

}

//--------------------------------------------------------------
void ofApp::update(){
	int s = fireworks.size();
	for (int i = s - 1; i >= 0; i--){
		fireworks.at(i).Update();
		if (fireworks.at(i).particles.empty()) {
			fireworks.erase(fireworks.begin() + i);
		}
	}

	chance = ofRandom(0, 1000) + increase_chance;
	if (chance > 999) {
		increase_chance = 0;
		int x = ofRandom(100, ofGetWindowWidth()-100);
		int y = ofRandom(100, ofGetWindowHeight()-100);
		fireworks.push_back(Firework(x, y));
	}
	else {
		increase_chance += 1;
	}
	//p.ApplyForce(gravity);
	//p.velocity += p.acceleration + gravity;
	//p.position += p.velocity;
	//p.acceleration *= 0;
}

//--------------------------------------------------------------
void ofApp::draw(){
	int s = fireworks.size();
	for (int i = 0; i < s; i++) {
		int sz = fireworks.at(i).particles.size();
		Particle *p;
		for (int j = 0; j < sz; j++) {
			p = &fireworks.at(i).particles.at(j);
			ofSetColor(p->red, p->green, p->blue , p->transparency);
			ofCircle(p->position.x, p->position.y, 5);
		}
	}

	ofSetColor(0, 0, 0);
	std::stringstream strm;
    strm << "FPS: " << ofGetFrameRate() << endl;
	strm << "cnt: " <<s;
	ofDrawBitmapString(strm.str(), 20, 20);
	
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
	fireworks.push_back(Firework(x, y));
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

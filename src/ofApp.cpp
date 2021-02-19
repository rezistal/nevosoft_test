#include "ofApp.h"
#include "Particle.h"
#include "Firework.h"

//Particle p;
//ofVec2f counter_force;
vector<Firework> fireworks;
//vector<int>::iterator the_iterator;

//--------------------------------------------------------------
void ofApp::setup(){
	gravity = ofVec2f(0, 0.05f);
/*	p.velocity.y = -5;
	p.velocity.x = 3;

	p.acceleration.y = p.velocity.y / -100;
	Firework f = Firework(100, 100);
	*/
}

//--------------------------------------------------------------
void ofApp::update(){
	int s = fireworks.size;
	for (int i = 0; i < s; i++){
		fireworks.at(i).Update();
	}
	//p.ApplyForce(gravity);
	//p.velocity += p.acceleration + gravity;
	//p.position += p.velocity;
	//p.acceleration *= 0;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);
	ofSetColor(255, 255, 255);
	ofCircle(100 + p.position.x, 250 + p.position.y, 10);
	/*
	std::stringstream strm;
	strm << "FPS: " << ofGetFrameRate();
	ofDrawBitmapString(strm.str(), 20, 20);
	*/
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

#include "Particle.h"
#include "ofApp.h"

Particle::Particle(int x, int y, ofColor color) {
	this->position = ofVec2f(x, y);
	float t = ofRandom(0, TWO_PI);
	float r = 1;
	float v = ofRandom(5, 10);
	this->velocity = ofVec2f(r*cos(t)*v, r*sin(t)*v);

	this->red = color.r + (int)ofRandom(-20, 20);
	this->green = color.g + (int)ofRandom(-20, 20);
	this->blue = color.b + (int)ofRandom(-20, 20);

	this->transparency = 400;

	this->slower = 5;
}

void Particle::ApplyForce(ofVec2f force) {
	this->acceleration += force;

}

void Particle::draw() {
	ofSetColor(this->red, this->green, this->blue, this->transparency);
	ofCircle(this->position.x, this->position.y, 5);
	ofSetColor(255, 255, 255);
	ofCircle(this->position.x, this->position.y, 2);
}

void Particle::Update() {
	ofVec2f gravity = ofVec2f(0, 0.4f);

	if (this->slower >= 0) {
		this->velocity *= 0.95f;
		this->slower--;
	}
	else {
		this->velocity += gravity;
	}

	//this->velocity += gravity;
	this->position += this->velocity;
	
	this->transparency -= (int)ofRandom(5, 10);
}

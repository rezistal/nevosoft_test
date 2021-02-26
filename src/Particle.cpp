#include "Particle.h"
#include "ofApp.h"

Particle::Particle(int x, int y) {
	this->position = ofVec2f(x, y);
	
}
void Particle::SetColor(ofColor color) {
	this->red = color.r + (int)ofRandom(-20, 20);
	this->green = color.g + (int)ofRandom(-20, 20);
	this->blue = color.b + (int)ofRandom(-20, 20);
}

void Particle::SetSlow(int slow) {
	this->slower = slow;
}

void Particle::InitParticle() {
	float t = ofRandom(0, TWO_PI);
	float r = 1;
	float v = ofRandom(5, 10);
	this->velocity = ofVec2f(r*cos(t)*v, r*sin(t)*v);
	this->transparency = 300;
	this->slow_step = 5;
}

//Частица передает набор данных для своей отрисовки
tuple<int, int, int, int, ofVec2f> Particle::Draw() {
	return make_tuple(this->red, this->green, this->blue, this->transparency, this->position);
}

// Частица рисует саму себя
void Particle::ofDraw() {
	ofSetColor(this->red, this->green, this->blue, this->transparency);
	ofCircle(this->position.x, this->position.y, 5);
	ofSetColor(255, 255, 255);
	ofCircle(this->position.x, this->position.y, 2);
}

void Particle::Update(int gravity) {

	if (this->slow_step >= 0) {
		this->velocity *= 0.85f + (float)(30-this->slower) / 100;
		this->slow_step--;
	}
	else {
		this->velocity.y += ((float)gravity / 10);
	}

	this->position += this->velocity;
	
	this->transparency -= (int)ofRandom(4, 6);
}

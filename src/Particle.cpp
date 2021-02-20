#include "Particle.h"
#include "ofApp.h"

Particle::Particle(int x, int y) {
	position = ofVec2f(x, y);
	float t = ofRandom(0, TWO_PI);
	float r = 0.5f;//ofRandom(0, 1);
	float v = ofRandom(4, 8);
	velocity = ofVec2f(r*cos(t)*v, r*sin(t)*v);
	//acceleration.x = velocity.x / -100; //ofRandom(-100, -50);
	//acceleration.y = velocity.y / -100; //ofRandom(-100, -50);

	red = ofRandom(0, 256);
	green = ofRandom(0, 256);
	blue = ofRandom(0, 256);

	transparency = 400;

	/*	p.velocity.y = -5;
		p.velocity.x = 3;

		p.acceleration.y = p.velocity.y / -100;
		*/
}

void Particle::ApplyForce(ofVec2f force) {
	this->acceleration += force;

}

void Particle::Update() {
	ofVec2f gravity = ofVec2f(0, 0.09f);
	ofVec2f old_v = velocity;
	velocity += acceleration;/*
	if (old_v.x / velocity.x < 0) {
		acceleration.x *= 0;
	}
	if (old_v.y / velocity.y < 0) {
		acceleration.y *= 0;
	}*/
	velocity += gravity;
	position += velocity;

	transparency -= (int)ofRandom(3, 5);
}

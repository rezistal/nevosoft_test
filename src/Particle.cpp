#include "Particle.h"
#include "ofApp.h"

Particle::Particle(int x, int y) {
	position = ofVec2f(x, y);
	velocity = ofVec2f(ofRandom(-5, 5), ofRandom(-5, 5));
	acceleration.x = velocity.x / ofRandom(-100, -25);
	acceleration.y = velocity.y / ofRandom(-100, -25);

}

void Particle::ApplyForce(ofVec2f force) {
	this->acceleration += force;

}

void Update() {

}

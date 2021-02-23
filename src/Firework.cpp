#include "Firework.h"

Firework::Firework(int x, int y) {
	this->center = ofVec2f(x, y);
}

void Firework::Init_particles() {
	float red = ofRandom(0, 256);
	float green = ofRandom(0, 256);
	float blue = ofRandom(0, 256);
	ofColor common_color = ofColor(red, green, blue);

	for (int i = 0; i <= this->particles_amount - 1; i++) {
		this->particles.push_back(Particle(this->center.x, this->center.y, common_color));
	}
}

void Firework::Update() {

	int transparent_particles = 0;
	Particle *particle;

	for (int i = this->particles_amount - 1; i >= 0; i--) {
		particle = &this->particles.at(i);
		particle->Update();
		if (particle->transparency <= 0) {
			transparent_particles += 1;
		}
	}
	if (transparent_particles == this->particles_amount) {
		this->done = true;
	}
}
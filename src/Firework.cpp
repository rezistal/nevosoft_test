#include "Firework.h"

Firework::Firework(int x, int y) {
	this->center = ofVec2f(x, y);
}

void Firework::InitParticles() {
	float red = ofRandom(0, 256);
	float green = ofRandom(0, 256);
	float blue = ofRandom(0, 256);
	ofColor common_color = ofColor(red, green, blue);

	for (int i = 0; i <= this->particles_amount - 1; i++) {
		this->particles.push_back(Particle(this->center.x, this->center.y, common_color));
	}
}

void Firework::SetParticlesAmount(int amount) {
	this->particles_amount = amount;
}

int Firework::GetParticlesAmount() {
	return this->particles_amount;
}

void Firework::SetGravity(int gravity) {
	this->gravity = gravity;
}

void Firework::Update() {

	int transparent_particles = 0;
	Particle *particle;

	for (int i = this->particles_amount - 1; i >= 0; i--) {
		particle = &this->particles.at(i);
		particle->Update(this->gravity);
		if (particle->transparency <= 0) {
			transparent_particles += 1;
		}
	}
	if (transparent_particles == this->particles_amount) {
		this->done = true;
	}
}

void Firework::Draw() {
	for (int i = 0; i <= this->particles_amount - 1; i++) {
		//this->particles.at(i).ofDraw();
		int red, green, blue, transparency;
		ofVec2f position;
		this->particles.at(i).Draw(&red, &green, &blue, &transparency, &position);
		ofSetColor(red, green, blue, transparency);
		ofCircle(position.x, position.y, 5);
		ofSetColor(255, 255, 255);
		ofCircle(position.x, position.y, 2);
	}
}

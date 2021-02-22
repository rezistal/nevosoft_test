#include "Firework.h"

Firework::Firework(int x, int y) {

	int particles_amount = (int)ofRandom(50, 100);

	float red = ofRandom(0, 256);
	float green = ofRandom(0, 256);
	float blue = ofRandom(0, 256);
	ofColor common_color = ofColor(red, green, blue);

	for (int i = 0; i <= particles_amount; i++){
		particles.push_back(Particle(x, y, common_color));
	}
}

void Firework::Update() {

	int particles_amount = particles.size();
	int transparent_particles = 0;
	Particle *particle;

	for (int i = particles_amount - 1; i >= 0; i--) {
		particle = &particles.at(i);
		particle->Update();
		if (particle->transparency < 0) {
			transparent_particles += 1;
		}
	}
	if (transparent_particles == particles_amount) {
		done = true;
	}
}
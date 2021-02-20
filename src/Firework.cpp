#include "Firework.h"

Firework::Firework(int x, int y) {

	int r = (int)ofRandom(2000, 3000);

	for (int i = 0; i <= r; i++){
		particles.push_back(Particle(x, y));
	}
}

void Firework::Update() {
	int s = particles.size();
	for (int i = s - 1; i >= 0; i--) {
		particles.at(i).Update();
		if (particles.at(i).transparency < 0) {
			particles.erase(particles.begin() + i);
		}
	}
}
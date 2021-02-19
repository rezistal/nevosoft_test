#include "Firework.h"

Firework::Firework(int x, int y) {
	
	int r = (int)ofRandom(1, 10);

	for (int i = 0; i <= r; i++){
		particles.push_back(Particle(x, y));
	}
}

void Firework::Update() {
	int s = particles.size;
	for (int i = 0; i < s; i++) {
		particles.at(i).Update();
	}
}
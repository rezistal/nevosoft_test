#pragma once
#include "ofMain.h"
#include "Particle.h"

class Firework
{

	public:
		vector<Particle> particles;

		Firework(int x, int y);
		void Update();
};


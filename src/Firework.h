#pragma once
#include "ofMain.h"
#include "Particle.h"

class Firework
{

	public:
		bool done = false;
		vector<Particle> particles;

		Firework(int x, int y);
		void Update();
};


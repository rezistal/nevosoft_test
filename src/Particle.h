#pragma once
#include "ofMain.h"

class Particle
{


	public:
		ofVec2f position;
		ofVec2f velocity;
		ofVec2f acceleration;

		Particle(int x, int y);
		void ApplyForce(ofVec2f force);
		void Update();
};


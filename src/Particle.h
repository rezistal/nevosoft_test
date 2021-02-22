#pragma once
#include "ofMain.h"

class Particle
{


	public:
		ofVec2f position;
		ofVec2f velocity;
		ofVec2f acceleration;

		int red;
		int green;
		int blue;
		int transparency;
		int slower;

		Particle(int x, int y, ofColor color);
		void ApplyForce(ofVec2f force);
		void draw();
		void Update();
};


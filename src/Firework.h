#pragma once
#include "ofMain.h"
#include "Particle.h"

//Класс фейрверка в котором много частиц
class Firework
{
	private:
		int gravity;
		int particles_amount;
	public:
		ofVec2f center;
		bool done = false;
		vector<Particle> particles;

		Firework(int x, int y);
		void InitParticles();
		void SetGravity(int gravity);
		void SetParticlesAmount(int amount);
		int GetParticlesAmount();
		void Update();
		void Draw();
};


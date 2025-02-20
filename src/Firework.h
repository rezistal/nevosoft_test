#pragma once
#include "ofMain.h"
#include "Particle.h"

//����� ��������� � ������� ����� ������
class Firework
{
	private:
		int gravity;
		int particles_amount;
		int slow;
		ofVec2f center;
		bool done = false;
		vector<Particle> particles;

	public:
		Firework(int x, int y);
		void InitParticles();
		void SetGravity(int gravity);
		void SetParticlesAmount(int amount);
		void SetSlow(int slow);
		int GetParticlesAmount();
		void Update();
		void Draw();
		bool GetDone();
};


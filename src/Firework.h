#pragma once
#include "ofMain.h"
#include "Particle.h"

//����� ��������� � ������� ����� ������
class Firework
{
	public:
		int particles_amount = 50;
		ofVec2f center;
		bool done = false;
		vector<Particle> particles;

		Firework(int x, int y);
		void Init_particles();
		void Update();
};


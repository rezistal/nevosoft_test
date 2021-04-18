#pragma once
#include "ofMain.h"

//����� �������
class Particle
{
	private:
		int red; // ������� ���������
		int green; // ������� ���������
		int blue; // ����� ���������
		int slower; // ����������
		ofVec2f position; // ������� ������� �� ������, ��� �� ������, �� ����������
		ofVec2f velocity; // ������ �������� �������
		ofVec2f acceleration; // ������ ���������
		int transparency; // ������������
		int slow_step;

	public:
		Particle(int x, int y);
		void ofDraw();
		tuple<int,int,int,int,ofVec2f> Draw();
		void Update(int gravity);
		void InitParticle();
		void SetColor(ofColor color);
		void SetSlow(int slow);
		int GetTransparency();
};
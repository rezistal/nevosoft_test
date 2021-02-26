#pragma once
#include "ofMain.h"

//����� �������
class Particle
{
	public:
		ofVec2f position; // ������� ������� �� ������, ��� �� ������, �� ����������
		ofVec2f velocity; // ������ �������� �������
		ofVec2f acceleration; // ������ ���������

		int red; // ������� ���������
		int green; // ������� ���������
		int blue; // ����� ���������
		int transparency; // ������������
		int slower; // ����������

		Particle(int x, int y, ofColor color);
		void ofDraw();
		tuple<int,int,int,int,ofVec2f> Draw();
		void Update(int gravity);
};


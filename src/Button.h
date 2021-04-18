#pragma once
#include "ofMain.h"
#include "Parameter.h"

//����� ������ �� ������
class Button
{
	private:
		ofImage *button_image_todraw; //����� �������� ������ � ������� ������
		ofImage *button_image; //������ �� �������� �� �������
		ofImage *button_image_pressed; // ������ �� ������� ��������

		int bx, by; // ���������� �������� ������ ���� ��������
		
	    //�������� � �������� ��������� ������
		Parameter app_param;

	public:
		Button();
		Button(ofImage *img, ofImage *img_p, int x, int y, Parameter p);
		
		int Click(int x, int y);
		void Click_released(int x, int y);
		void Draw();
};


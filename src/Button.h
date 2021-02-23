#pragma once
#include "ofMain.h"
#include "Parameter.h"

//����� ������ �� ������
class Button
{
	public:
		ofImage *button_image_todraw; //����� �������� ������ � ������� ������
		ofImage *button_image; //������ �� �������� �� �������
		ofImage *button_image_pressed; // ������ �� ������� ��������

		int bx, by; // ���������� �������� ������ ���� ��������
		
	    //�������� � �������� ��������� ������
		Parameter<int> app_param_int; 
		//�������� � �������� ��������� ������
		Parameter<float> app_param_float;
		//������� ��� �� ���� ������� � ����� ���������� ���������� ��� ��������� ���������
		//���� �� ������� ��� ��������� ��������� � ������� ��������� � ���� ����������
		//��� ��� ���������� � ������� ������������ ��������� ��� ������� ������ 
		string bicycle;

		Button();
		Button(ofImage *img, ofImage *img_p, int x, int y, Parameter<int> p);
		Button(ofImage *img, ofImage *img_p, int x, int y, Parameter<float> p);
		
		void Click(int x, int y);
		void Click_released(int x, int y);
		void Draw();
};


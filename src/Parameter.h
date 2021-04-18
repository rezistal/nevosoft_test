#pragma once
#include "ofMain.h"

class Parameter
{
	private:
		int *app_param; // �������� ���������� ������� ����������

		//��� ��� �������� ����� �������� ������� �� ������� ��� �� ������ �������� ����� ���� ���-������ ���������
		int step; // ��� �����������
		int sign; // ����������� �����������
		int invert; // �������� �������� �����������

		int minvalue; // ����������� ��������
		int maxvalue; // ������������ ��������

	public:
		Parameter() {

		}

		Parameter(int *param, int step, int sign, int invert, int minvalue, int maxvalue) {
			this->app_param = param;
			this->step = step;
			this->sign = sign;
			this->invert = invert;
			this->minvalue = minvalue;
			this->maxvalue = maxvalue;
		}

		void Applystep() {
			int new_val = (*this->app_param * this->invert) + (this->step * this->sign);
			if (new_val >= this->minvalue && new_val <= this->maxvalue) {
				*this->app_param = new_val;
			}
		}
};
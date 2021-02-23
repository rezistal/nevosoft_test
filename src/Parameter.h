#pragma once
#include "ofMain.h"

template<typename T>
class Parameter
{
	public:
		T *app_param; // �������� ���������� ������� ����������
		T step; // ��� �����������
		T sign; // ����������� �����������
		T invert; // �������� �������� �����������
		T minvalue; // ����������� ��������
		T maxvalue; // ������������ ��������

		Parameter() {

		}

		Parameter(T *param, T step, T sign, T invert, T minvalue, T maxvalue) {
			this->app_param = param;
			this->step = step;
			this->sign = sign;
			this->invert = invert;
			this->minvalue = minvalue;
			this->maxvalue = maxvalue;
		}

		void Applystep() {
			T new_val = (*this->app_param * this->invert) + (this->step * this->sign);
			if (new_val >= this->minvalue && new_val <= this->maxvalue) {
				*this->app_param = new_val;
			}
		}
};
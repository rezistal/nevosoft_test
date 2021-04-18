#pragma once
#include "ofMain.h"

class Parameter
{
	private:
		int *app_param; // Параметр приложения который регулируем

		//Эти три наверное стоит заменить ссылкой на функцию что бы менять параметр можно было как-нибудь уникально
		int step; // Шаг регулировки
		int sign; // Направление регулировки
		int invert; // Обратное значение регулировки

		int minvalue; // Минимальное значение
		int maxvalue; // Максимальное значение

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
#pragma once
#include "ofMain.h"
#include "Parameter.h"

//Класс кнопки на экране
class Button
{
	public:
		ofImage *button_image_todraw; //Какую картинку рисуем в текущий момент
		ofImage *button_image; //Ссылка на картинку не нажатую
		ofImage *button_image_pressed; // Ссылка на нажатую картинку

		int bx, by; // Координаты верхнего левого угла картинки
		
	    //Параметр к которому привязана кнопка
		Parameter<int> app_param_int; 
		//Параметр к которому привязана кнопка
		Parameter<float> app_param_float;
		//Костыль что бы было понятно к какой переменной обращаться для изменения параметра
		//Пока не понимаю как запихнуть параметры с разными шаблонами в одну переменную
		//Или как обратиться к нужному заполненному аттрибуту для запуска метода 
		string bicycle;

		Button();
		Button(ofImage *img, ofImage *img_p, int x, int y, Parameter<int> p);
		Button(ofImage *img, ofImage *img_p, int x, int y, Parameter<float> p);
		
		void Click(int x, int y);
		void Click_released(int x, int y);
		void Draw();
};


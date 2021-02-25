#pragma once
#include "ofMain.h"

//Класс частицы
class Particle
{
	public:
		ofVec2f position; // Позиция частицы на экране, как бы вектор, но координаты
		ofVec2f velocity; // Вектор скорости частицы
		ofVec2f acceleration; // Вектор ускорения

		int red; // Красный компонент
		int green; // Зеленый компонент
		int blue; // Синий компонент
		int transparency; // Прозрачность
		int slower; // Замедление

		Particle(int x, int y, ofColor color);
		void ofDraw();
		void Draw(int *red, int *green, int *blue, int *transparency, ofVec2f *position);
		void Update(int gravity);
};


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
		void ApplyForce(ofVec2f force);
		void draw();
		void Update();
};


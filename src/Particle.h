#pragma once
#include "ofMain.h"

//Класс частицы
class Particle
{
	private:
		int red; // Красный компонент
		int green; // Зеленый компонент
		int blue; // Синий компонент
		int slower; // Замедление
		ofVec2f position; // Позиция частицы на экране, как бы вектор, но координаты
		ofVec2f velocity; // Вектор скорости частицы
		ofVec2f acceleration; // Вектор ускорения
		int transparency; // Прозрачность
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
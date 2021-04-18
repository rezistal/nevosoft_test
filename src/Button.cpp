#include "Button.h"

Button::Button() {

}

Button::Button(ofImage *img, ofImage *img_p, int x, int y, Parameter p) {
	this->bx = x;
	this->by = y;
	this->button_image = img;
	this->button_image_pressed = img_p;
	this->button_image_todraw = img;
	this->app_param = p;
}

void Button::Draw() {
	this->button_image_todraw->draw(this->bx, this->by);
}


int Button::Click(int x, int y) {
	if (x >= this->bx
		&& x <= this->bx + this->button_image->getWidth()
		&& y >= this->by
		&& y <= this->by + this->button_image->getHeight()
		) {
			this->app_param.Applystep();
			
			this->button_image_todraw = this->button_image_pressed;
			return 1;
	}
	return 0;
}

void Button::Click_released(int x, int y) {
	this->button_image_todraw = this->button_image;
}
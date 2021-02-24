#include "ofApp.h"

float chance;
float increase_chance = 0;
int fireworks_count = 0;
int particles_count = 0;
int click_detector;

Parameter<int> ptest;
Parameter<int> ptest2;

ofApp::ofApp() {

}

bool ofApp::isGamePaused() {
	if (this->param_pause == 1) {
		return true;
	}
	return false;
}

//--------------------------------------------------------------
void ofApp::setup(){
	//Инициализируем стартовые параметры
	this->param_particles_in_firework = 50;
	this->param_pause = -1;
	this->param_gravity = 0.4f;

	//Загружаем все картинки
	this->img_button_up.loadImage("button_up.png");
	this->img_button_up_pressed.loadImage("button_up_pressed.png");
	this->img_button_down.loadImage("button_down.png");
	this->img_button_down_pressed.loadImage("button_down_pressed.png");
	this->img_button_pause.loadImage("pause.png");
	this->img_button_pause_pressed.loadImage("pause_pressed.png");

	this->img_pause_menu.loadImage("ask.png");

	//Создаем кнопки
	this->inc_particles_in_firework = Button(&img_button_up, &img_button_up_pressed, 20, 80, Parameter<int>(&this->param_particles_in_firework, 1, 1, 1, 1, 1000));
	this->dec_particles_in_firework = Button(&img_button_down, &img_button_down_pressed, 80, 80, Parameter<int>(&this->param_particles_in_firework, 1, -1, 1, 1, 1000));
	this->pause = Button(&img_button_pause, &img_button_pause_pressed, 20, 200, Parameter<int>(&this->param_pause, 0, 0, -1, -1, 1));

	//Название окна
	ofSetWindowTitle("Nevosoft fireworks!");

	//Цвет ночного неба
	ofBackground(13, 7, 46);

	//ofSetBackgroundAuto(false);
	//ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

	if (!isGamePaused()) {

		//Вычисляем движение всех частиц для каждого из фейрверков
		int s = fireworks.size();
		for (int i = s - 1; i >= 0; i--) {
			Firework *f = &fireworks.at(i);
			f->Update();
			if (f->done) {
				fireworks.erase(fireworks.begin() + i);
			}
		}

		//Шанс создать в случайном месте фейрверк
		//Если не создался - увеличиваем шанс создания
		if (true) {
			chance = ofRandom(0, 10000) + increase_chance;
			if (chance > 9999) {
				increase_chance = 0;
				int x = ofRandom(100, ofGetWindowWidth() - 100);
				int y = ofRandom(100, ofGetWindowHeight() - 100);

				Firework f = Firework(x, y);
				f.particles_amount = this->param_particles_in_firework;
				f.Init_particles();

				fireworks.push_back(f);
				particles_count += f.particles_amount;
				fireworks_count += 1;

			}
			else {
				increase_chance += 1;
			}
		}

	}
	else {
		//OF_EXIT_APP(0);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	int s = fireworks.size();
	
	for (int i = 0; i < s; i++) {
		int sz = fireworks.at(i).particles.size();
		Particle *p;
		for (int j = 0; j < sz; j++) {
			p = &fireworks.at(i).particles.at(j);
			p->draw();
			//ofSetColor(p->red, p->green, p->blue , p->transparency);
			//ofCircle(p->position.x, p->position.y, 5);
		}
	}

	ofSetColor(255, 255, 255);
	std::stringstream strm;
	strm << "FPS: " << (int)ofGetFrameRate() << endl;
	strm << "Current cnt: " << s << endl;
	strm << "Total fireworks cnt: " << fireworks_count << endl;
	strm << "Total particles cnt: " << particles_count << endl;
	ofDrawBitmapString(strm.str(), 20, 20);
	ofDrawBitmapString(this->param_particles_in_firework, 60, 100);

	this->inc_particles_in_firework.Draw();
	this->dec_particles_in_firework.Draw();
	this->pause.Draw();

	if (isGamePaused()) {
		this->img_pause_menu.draw(0, 0);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	click_detector = 0;

	if (!isGamePaused()) {
		click_detector += this->inc_particles_in_firework.Click(x, y);
		click_detector += this->dec_particles_in_firework.Click(x, y);
		click_detector += this->pause.Click(x, y);
	}

	if (!isGamePaused() && click_detector == 0) {

		Firework f = Firework(x, y);
		f.particles_amount = this->param_particles_in_firework;
		f.Init_particles();

		fireworks.push_back(f);
		particles_count += f.particles_amount;
		fireworks_count += 1;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	this->inc_particles_in_firework.Click_released(x, y);
	this->dec_particles_in_firework.Click_released(x, y);
	this->pause.Click_released(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

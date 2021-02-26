#include "ofApp.h"

ofApp::ofApp() {

}

bool ofApp::GamePaused() {
	if (this->app_param_pause == 1) {
		return true;
	}
	return false;
}

//--------------------------------------------------------------
void ofApp::setup(){
	this->fireworks.reserve(20);
	//Инициализируем стартовые параметры
	this->param_particles_in_firework = 50;
	this->param_gravity = 3;

	this->app_param_pause = -1;
	this->app_param_exit = -1;
	this->app_param_chance = 0;
	this->app_param_increase_chance = 0;
	this->app_param_fireworks_count = 0;
	this->app_param_particles_count = 0;


	//Загружаем все картинки
	this->img_button_up.loadImage("button_up.png");
	this->img_button_up_pressed.loadImage("button_up_pressed.png");
	this->img_button_down.loadImage("button_down.png");
	this->img_button_down_pressed.loadImage("button_down_pressed.png");
	this->img_button_pause.loadImage("pause.png");
	this->img_button_pause_pressed.loadImage("pause_pressed.png");

	this->img_button_resume.loadImage("resume.png");
	this->img_button_exit.loadImage("exit.png");

	this->img_pause_menu.loadImage("popup.png");

	this->img_sky.loadImage("sky.png");
	this->img_window.loadImage("window.png");
	this->img_window_light.loadImage("window_light.png");

	//Создаем кнопки
	//Регулировки
	this->buttons_layer0[0] = Button(&img_button_up, &img_button_up_pressed, 90, 80, Parameter<int>(&this->param_particles_in_firework, 1, 1, 1, 1, 1000));
	this->buttons_layer0[1] = Button(&img_button_down, &img_button_down_pressed, 20, 80, Parameter<int>(&this->param_particles_in_firework, 1, -1, 1, 1, 1000));
	this->buttons_layer0[2] = Button(&img_button_up, &img_button_up_pressed, 90, 130, Parameter<int>(&this->param_gravity, 1, 1, 1, 0, 9));
	this->buttons_layer0[3] = Button(&img_button_down, &img_button_down_pressed, 20, 130, Parameter<int>(&this->param_gravity, 1, -1, 1, 0, 9));

	//Меню пауза/выход
	this->buttons_layer0[4] = Button(&img_button_pause, &img_button_pause_pressed, 20, 200, Parameter<int>(&this->app_param_pause, 0, 0, -1, -1, 1));
	this->buttons_layer1[0] = Button(&img_button_resume, &img_button_resume, 320, 275, Parameter<int>(&this->app_param_pause, 0, 0, -1, -1, 1));
	this->buttons_layer1[1] = Button(&img_button_exit, &img_button_exit, 420, 275, Parameter<int>(&this->app_param_exit, 0, 0, -1, -1, 1));

	//Название окна
	ofSetWindowTitle("Nevosoft fireworks!");
}

//--------------------------------------------------------------
void ofApp::update(){

	if (!GamePaused()) {

		//Вычисляем движение всех частиц для каждого из фейрверков
		int s = fireworks.size();
		for (int i = s - 1; i >= 0; i--) {
			Firework *f = &fireworks.at(i);
			f->SetGravity(this->param_gravity);
			f->Update();
			if (f->done) {
				fireworks.erase(fireworks.begin() + i);
			}
		}

		//Шанс создать в случайном месте фейрверк
		//Если не создался - увеличиваем шанс создания
		if (true) {
			this->app_param_chance = (int)ofRandom(0, 10000) + this->app_param_increase_chance;
			if (this->app_param_chance > 9999) {
				this->app_param_increase_chance = 0;
				int x = ofRandom(100, ofGetWindowWidth() - 100);
				int y = ofRandom(100, ofGetWindowHeight() - 100);

				Firework f = Firework(x, y);
				f.SetParticlesAmount(this->param_particles_in_firework);
				f.InitParticles();

				fireworks.push_back(f);
				this->app_param_particles_count += this->param_particles_in_firework;
				this->app_param_fireworks_count += 1;

			}
			else {
				this->app_param_increase_chance += 1;
			}
		}

	}
	if(this->app_param_exit == 1) {
		OF_EXIT_APP(0);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	//1 Слой: Рисуем небо
	this->img_sky.draw(0,0);

	int s = fireworks.size();
	for (int i = 0; i < s; i++) {
		//2 Слой: Рисуем фейрверки
		fireworks.at(i).Draw();
	}

	//3 Слой: Рисуем оконную раму
	if (s != 0) {
		this->img_window_light.draw(0, 0);
	}
	else {
		this->img_window.draw(0, 0);
	}
	
	//4 Слой: Рисуем чиселки
	ofSetColor(255, 255, 255);
	stringstream strm;
	strm << "FPS: " << (int)ofGetFrameRate() << endl;
	strm << "Current fireworks: " << s << endl;
	strm << "Total fireworks: " << this->app_param_fireworks_count << endl;
	strm << "Total particles: " << this->app_param_particles_count << endl;
	strm << "Firework particles: " << endl;
	ofDrawBitmapString(strm.str(), 20, 20);
	ofDrawBitmapString(this->param_particles_in_firework, 65, 100);
	ofDrawBitmapString("Gravity force:", 20, 120);
	ofDrawBitmapString("0." + to_string(this->param_gravity), 60, 150);


	//4 Слой: Рисуем кнопки
	for (Button b : this->buttons_layer0) {
		b.Draw();
	}

	//5 Слой: Рисуем оверлэй паузы и кнопки
	if (GamePaused()) {
		this->img_pause_menu.draw(0, 0);
		for (Button b : this->buttons_layer1) {
			b.Draw();
		}
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
	this->app_param_click_detector = 0;

	if (!GamePaused()) {
		for (Button b : this->buttons_layer0) {
			this->app_param_click_detector += b.Click(x, y);
		}
	}
	else {
		for (Button b : this->buttons_layer1) {
			this->app_param_click_detector += b.Click(x, y);
		}
	}

	if (!GamePaused() && this->app_param_click_detector == 0) {

		Firework f = Firework(x, y);
		f.SetParticlesAmount(this->param_particles_in_firework);
		f.InitParticles();

		fireworks.push_back(f);
		this->app_param_particles_count += this->param_particles_in_firework;
		this->app_param_fireworks_count += 1;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	for (Button b : this->buttons_layer0) {
		b.Click_released(x, y);
	}
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

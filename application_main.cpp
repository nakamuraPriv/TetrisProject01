#include "application_main.h"
#include "scene.h"
#include "title.h"

using namespace std;

ApplicationMain::ApplicationMain() 
:quit(false){
	this->curr_scene = make_shared<Title>();
}

void ApplicationMain::set_inputs(shared_ptr<Inputs> inputs) {
	this->inputs = inputs;
}

void ApplicationMain::run() {
	this->inputs->update_inputs();
	shared_ptr<Scene> next_scene = this->curr_scene->run(shared_from_this());
	if (next_scene != this->curr_scene) {
		curr_scene = next_scene;
	}
}

bool ApplicationMain::is_quit() {
	return this->quit;
}

void ApplicationMain::set_quit(bool quit) {
	this->quit = quit;
}

long ApplicationMain::get_key_pushed_time(Inputs::KEY_TYPE key) {
	return this->inputs->get_pushed_time(key);
}
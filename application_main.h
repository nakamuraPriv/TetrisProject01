#pragma once
#include <memory>
#include "inputs.h"

class Scene;

class ApplicationMain : public std::enable_shared_from_this<ApplicationMain>{
private:
	std::shared_ptr<Scene> curr_scene;
	std::shared_ptr<Inputs> inputs;
	bool quit;
public:
	ApplicationMain();
	void set_inputs(std::shared_ptr<Inputs> inputs);
	void run();
	bool is_quit();
	void set_quit(bool quit);
	long get_key_pushed_time(Inputs::KEY_TYPE key);
};
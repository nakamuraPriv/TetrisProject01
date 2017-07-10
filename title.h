#pragma once
#include "scene.h"
#include <memory>
#include <string>

class ApplicationMain;
class Select;

class Title : public Scene, public std::enable_shared_from_this<Title> {
private:
	std::string title_text;
	std::string cursol;
	std::shared_ptr<Select> menu;
	std::shared_ptr<Scene> update(std::shared_ptr<ApplicationMain> application_main);
	void display(std::shared_ptr<ApplicationMain> application_main);
public:
	Title();
	std::shared_ptr<Scene> run(std::shared_ptr<ApplicationMain> application_main);
};
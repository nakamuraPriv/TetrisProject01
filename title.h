#pragma once
#include "scene.h"
#include <memory>
#include <string>

class ApplicationMain;

class Title : public Scene, public std::enable_shared_from_this<Title> {
private:
	std::string title_text;
public:
	Title();
	std::shared_ptr<Scene> run(std::shared_ptr<ApplicationMain> application_main);
};
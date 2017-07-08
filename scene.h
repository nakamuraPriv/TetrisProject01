#pragma once
#include <memory>

class ApplicationMain;

class Scene {
public:
	virtual std::shared_ptr<Scene> run(std::shared_ptr<ApplicationMain> application_main) = 0;
};
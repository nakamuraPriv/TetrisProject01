#pragma once
#include "scene.h"
#include <memory>

class ApplicationMain;

class TetrisOnePlay : public Scene, public std::enable_shared_from_this<TetrisOnePlay>{
private:
	int cell_size;
	int frame_left_x;
	int frame_up_y;
	std::shared_ptr<Scene> update(std::shared_ptr<ApplicationMain> application_main);
	void display(std::shared_ptr<ApplicationMain> application_main);
	void draw_frame(std::shared_ptr<ApplicationMain> application_main);
public:
	TetrisOnePlay();
	std::shared_ptr<Scene> run(std::shared_ptr<ApplicationMain> application_main);
};
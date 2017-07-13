#include "tetris_one_play.h"
#include "application_main.h"
#include "const_values.h"
#include "DxLib.h"

using namespace std;

shared_ptr<Scene> TetrisOnePlay::run(shared_ptr<ApplicationMain> application_main) {
	display(application_main);
	shared_ptr<Scene> next_scene = update(application_main);

	return next_scene;
}

TetrisOnePlay::TetrisOnePlay() {
	this->cell_size = ConstValues::get_instance().get_cell_size();
	this->frame_left_x = 36;
	this->frame_up_y = 36;
}

shared_ptr<Scene> TetrisOnePlay::update(shared_ptr<ApplicationMain> application_main) {
	shared_ptr<Scene> next_scene = shared_from_this();

	return next_scene;
}

void TetrisOnePlay::display(shared_ptr<ApplicationMain> application_main) {
	//TODO:フレームを表示
	this->draw_frame(application_main);
}

void TetrisOnePlay::draw_frame(shared_ptr<ApplicationMain> application_main) {
	//内側のラインの描画
	DrawLineBox(
		this->frame_left_x + this->cell_size,
		this->frame_up_y + this->cell_size,
		this->frame_left_x + this->cell_size + (this->cell_size * 10),
		this->frame_up_y + this->cell_size + (this->cell_size * 20),
		GetColor(0, 100, 255));
	//外側のラインの描画
	DrawLineBox(
		this->frame_left_x,
		this->frame_up_y,
		this->frame_left_x + (this->cell_size * 12),
		this->frame_up_y + (this->cell_size * 22),
		GetColor(0, 100, 255));
}
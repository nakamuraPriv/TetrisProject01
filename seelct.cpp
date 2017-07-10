#include "select.h"
#include "DxLib.h"
#include "scene.h"
#include "application_main.h"

using namespace std;

Select::Select()
	:curr_selected_index(0),x(0),y(0),cycle_flag(false),font_size(24) {
	this->options.clear();
	this->font_handle = CreateFontToHandle(NULL, this->font_size, 0);
}

Select::~Select() {
	DeleteFontToHandle(this->font_handle);
}

void Select::add_option(
	string key,
	function<shared_ptr<Scene>(shared_ptr<ApplicationMain>,shared_ptr<Scene>)> func) {
	Option option;
	option.set_key(key);
	option.set_func(func);
	this->options.push_back(option);
}

int Select::get_options_num() {
	return this->options.size();
}

int Select::get_curr_selected_index() {
	return this->curr_selected_index;
}

void Select::next() {
	int next_index = this->curr_selected_index + 1;
	if (next_index >= this->options.size()) {
		if (cycle_flag) {
			next_index = 0;
		} else {
			next_index = this->curr_selected_index;
		}
	}
	this->curr_selected_index = next_index;
}

void Select::back() {
	int next_index = this->curr_selected_index - 1;
	if (next_index < 0) {
		if (cycle_flag) {
			next_index = this->options.size() - 1;
		} else {
			next_index = this->curr_selected_index;
		}
	}
	this->curr_selected_index = next_index;
}

void Select::set_coord(int x, int y) {
	this->x = x;
	this->y = y;
}

void Select::set_cycle_flag(bool cycle_flag) {
	this->cycle_flag = cycle_flag;
}

void Select::set_font_size(int font_size) {
	this->font_size = font_size;
	DeleteFontToHandle(this->font_handle);
	this->font_handle = CreateFontToHandle(NULL, this->font_size, 0);
}

void Select::display() {
	int draw_x = this->x;
	int draw_y = this->y;
	int buf_size = this->font_size / 2;
	for (unsigned int i = 0; i < this->options.size(); i++) {
		if (i == this->curr_selected_index) {
			DrawFormatStringToHandle(draw_x, draw_y + i * (this->font_size + buf_size), GetColor(255, 255, 255), this->font_handle, "¡");
		}
		DrawFormatStringToHandle(draw_x + 36, draw_y + i*(this->font_size + buf_size), GetColor(255, 255, 255), this->font_handle, options[i].get_key().c_str());
	}
}

shared_ptr<Scene> Select::operate_func(
	shared_ptr<ApplicationMain> application_main,
	shared_ptr<Scene> scene) {
	return this->options[this->curr_selected_index].get_func()(application_main, scene);
}
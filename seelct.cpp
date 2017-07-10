#include "select.h"
#include "DxLib.h"

using namespace std;

Select::Select()
	:curr_selected_index(0),x(0),y(0),cycle_flag(false),font_size(24) {
	this->options.clear();
}

void Select::add_option(
	string key,
	function<vector<string>(vector<string>)> func) {
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
}

void Select::display() {
	int draw_x = this->x;
	int draw_y = this->y;
	//TODO:options‚Ì’†g‚ğ‰ñ‚µ‚È‚ª‚ç•`‰æ
}
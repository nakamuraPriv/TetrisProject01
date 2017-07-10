#pragma once

#include <vector>
#include <string>
#include <functional>
#include <memory>
#include "DxLib.h"

class ApplicationMain;
class Scene;

class Select {
private:
	class Option {
	private:
		std::string key;
		std::function<std::shared_ptr<Scene>(std::shared_ptr<ApplicationMain>, std::shared_ptr<Scene>)> func;
	public:
		Option() {
			key = "";
		}
		void set_key(std::string key) {
			this->key = key;
		}
		std::string get_key() {
			return this->key;
		}

		void set_func(std::function<std::shared_ptr<Scene>(std::shared_ptr<ApplicationMain>,std::shared_ptr<Scene>)> func) {
			this->func = func;
		}

		auto get_func() {
			return this->func;
		}
	};

	std::vector<Option> options;
	int curr_selected_index;
	int x;
	int y;
	bool cycle_flag;
	int font_size;
	int font_handle;

public:
	Select();
	~Select();
	Select(const Select& obj) = default;
	Select& operator=(const Select& obj) = default;
	void add_option(
		std::string key,
		std::function<std::shared_ptr<Scene>(std::shared_ptr<ApplicationMain>, std::shared_ptr<Scene>)> func);
	int get_options_num();
	int get_curr_selected_index();
	void next();
	void back();
	void set_coord(int x, int y);
	void set_cycle_flag(bool cycle_flag);
	void set_font_size(int font_size);

	void display();
	std::shared_ptr<Scene> operate_func(std::shared_ptr<ApplicationMain> application_main, std::shared_ptr<Scene> scene);

};
#pragma once

#include <vector>
#include <string>
#include <functional>

class Select {
private:
	class Option {
	private:
		std::string key;
		std::function<std::vector<std::string>(std::vector<std::string>)> func;
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

		void set_func(std::function<std::vector<std::string>(std::vector<std::string>)> func) {
			this->func = func;
		}
	};

	std::vector<Option> options;
	int curr_selected_index;
	int x;
	int y;
	bool cycle_flag;
	int font_size;

public:
	Select();
	Select(const Select& obj) = default;
	Select& operator=(const Select& obj) = default;
	void add_option(
		std::string key,
		std::function<std::vector<std::string>(std::vector<std::string>)> func);
	int get_options_num();
	int get_curr_selected_index();
	void next();
	void back();
	void set_coord(int x, int y);
	void set_cycle_flag(bool cycle_flag);
	void set_font_size(int font_size);

	void display();

};
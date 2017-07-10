#pragma once

#include <vector>
#include <string>
#include <functional>

class Select {
private:
	class Option {
	private:
		std::string key;
		std::function<void(void)> func;
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
	};

	std::vector<Option> options;

public:

};
#pragma once

#include <string>

class ConstValues {
private:
	ConstValues();
	std::string title;
	int cell_size;
public:
	static ConstValues& get_instance();
	~ConstValues() = default;
	ConstValues(const ConstValues& obj) = delete;
	ConstValues& operator=(const ConstValues& obj) = delete;
	std::string get_title();
	int get_cell_size();
};
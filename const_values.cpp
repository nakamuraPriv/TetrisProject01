#include "const_values.h"

using namespace std;

ConstValues::ConstValues() {
	title = "ƒeƒgƒŠƒX";
	cell_size = 20;
}

ConstValues& ConstValues::get_instance() {
	static ConstValues instance;

	return instance;
}

string ConstValues::get_title() {
	return this->title;
}

int ConstValues::get_cell_size() {
	return this->cell_size;
}
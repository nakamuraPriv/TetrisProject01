#include "const_values.h"

using namespace std;

ConstValues::ConstValues() {
	title = "�e�g���X";
}

ConstValues& ConstValues::get_instance() {
	static ConstValues instance;

	return instance;
}

string ConstValues::get_title() {
	return this->title;
}
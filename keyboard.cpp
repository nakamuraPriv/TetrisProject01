#include "keyboard.h"
#include "DxLib.h"

using namespace std;

void KeyBoard::update_keyboard() {
	char buf[256];
	GetHitKeyStateAll(buf);
	for (unsigned int i = 0; i < 256; i++) {
		if (buf[i] != 0) {
			this->pushed_times[i]++;
		} else {
			this->pushed_times[i] = 0;
		}
	}
}

long KeyBoard::get_pushed_time(int key) {
	return this->pushed_times[key];
}
#pragma once

class KeyBoard {
private:
	long pushed_times[256];
public:
	KeyBoard() = default;

	void update_keyboard();
	long get_pushed_time(int key);
};
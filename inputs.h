#pragma once
#include <memory>

class KeyBoard;
/*
キーボードやパッドなど入力のラッパークラス。
*/
class Inputs {
private:
	std::shared_ptr<KeyBoard> keyboard;
public:
	enum KEY_TYPE {
		KEY_A,
		KEY_Z,
		KEY_S,
		KEY_W,
		KEY_RIGHT,
		KEY_LEFT,
		KEY_UP,
		KEY_BOTTOM,
		KEY_SPACE,
		KEY_ENTER,
		NONE
	};
	Inputs();
	void update_inputs();
	long get_pushed_time(KEY_TYPE key);
};
#include "inputs.h"

#include "keyboard.h"
#include "DxLib.h"

using namespace std;

Inputs::Inputs() {
	this->keyboard = make_shared<KeyBoard>();
}

void Inputs::update_inputs() {
	/*
	�S�Ă̓��͂̏����A�b�v�f�[�g����
	*/
	this->keyboard->update_keyboard();
}

long Inputs::get_pushed_time(Inputs::KEY_TYPE key) {
	/*
	�������ɏ]���Ċe���̓f�o�C�X���炻�̃L�[�̉�����Ă��鎞�Ԃ��擾���A
	�ł������f�o�C�X�̓��͎��Ԃ�Ԃ�
	*/
	long result = 0;
	switch (key) {
	case KEY_A:
		result = this->keyboard->get_pushed_time(KEY_INPUT_A);
		break;
	case KEY_Z:
		result = this->keyboard->get_pushed_time(KEY_INPUT_Z);
		break;
	case KEY_S:
		result = this->keyboard->get_pushed_time(KEY_INPUT_S);
		break;
	case KEY_W:
		result = this->keyboard->get_pushed_time(KEY_INPUT_W);
		break;
	case KEY_RIGHT:
		result = this->keyboard->get_pushed_time(KEY_INPUT_RIGHT);
		break;
	case KEY_LEFT:
		result = this->keyboard->get_pushed_time(KEY_INPUT_LEFT);
		break;
	case KEY_UP:
		result = this->keyboard->get_pushed_time(KEY_INPUT_UP);
		break;
	case KEY_BOTTOM:
		result = this->keyboard->get_pushed_time(KEY_INPUT_DOWN);
		break;
	case KEY_SPACE:
		result = this->keyboard->get_pushed_time(KEY_INPUT_SPACE);
		break;
	case KEY_ENTER:
		result = this->keyboard->get_pushed_time(KEY_INPUT_RETURN);
		break;
	default:
		break;
	}
	return result;
}
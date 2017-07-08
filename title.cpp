#include "title.h"
#include "application_main.h"
#include "DxLib.h"
#include "inputs.h"

using namespace std;

shared_ptr<Scene> Title::run(shared_ptr<ApplicationMain> application_main) {
	shared_ptr<Scene> next_scene = shared_from_this();

	DrawFormatString(200, 100, GetColor(100, 100, 0), title_text.c_str());

	if (application_main->get_key_pushed_time(Inputs::KEY_A) > 10) {
		application_main->set_quit(true);
	}

	return next_scene;
}

Title::Title() {
	/*TODO:�ݒ�t�@�C����R���t�B�O�t�@�C������ݒ��ǂݍ���
	�����o�ϐ��ɒl���Z�b�g����*/
	this->title_text = "�e�g���X!!";
}
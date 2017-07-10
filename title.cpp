#include "title.h"
#include "application_main.h"
#include "DxLib.h"
#include "inputs.h"
#include "const_values.h"
#include "select.h"

using namespace std;

shared_ptr<Scene> Title::update(shared_ptr<ApplicationMain> application_main) {
	shared_ptr<Scene> next_scene = shared_from_this();
	if (application_main->get_key_pushed_time(Inputs::KEY_A) > 10) {
		application_main->set_quit(true);
	}

	if (application_main->get_key_pushed_time(Inputs::KEY_BOTTOM) == 1) {
		this->menu->next();
	}
	if (application_main->get_key_pushed_time(Inputs::KEY_UP) == 1) {
		this->menu->back();
	}

	if (application_main->get_key_pushed_time(Inputs::KEY_A) == 1) {
		next_scene = this->menu->operate_func(application_main, shared_from_this());
	}

	return next_scene;
}

void Title::display(shared_ptr<ApplicationMain> application_main) {
	DrawFormatString(200, 100, GetColor(100, 100, 0), title_text.c_str());
	this->menu->display();
}

shared_ptr<Scene> Title::run(shared_ptr<ApplicationMain> application_main) {
	this->display(application_main);
	shared_ptr<Scene> next_scene = this->update(application_main);

	

	

	return next_scene;
}

Title::Title() {
	/*TODO:�ݒ�t�@�C����R���t�B�O�t�@�C������ݒ��ǂݍ���
	�����o�ϐ��ɒl���Z�b�g����*/
	this->title_text = ConstValues::get_instance().get_title();
	this->cursol = "��";
	this->menu = make_shared<Select>();
	this->menu->set_cycle_flag(true);
	this->menu->set_coord(240, 360);
	this->menu->set_font_size(16);
	this->menu->add_option(
		"�ЂƂ�ŗV��",
		[this](
			shared_ptr<ApplicationMain> application_main,
			shared_ptr<Scene> scene)->shared_ptr<Scene> {
		//TODO:�ЂƂ�v���C�p�Q�[����ʂ֔�ԏ���������B
		return shared_from_this();
	});
	this->menu->add_option(
		"�ʐM�ΐ�ŗV��",
		[this](
			shared_ptr<ApplicationMain> application_main,
			shared_ptr<Scene> scene)->shared_ptr<Scene> {
		//TODO:�ΐ푊���T����ʂ֔�ԏ���������B
		return shared_from_this();
	}
	);
	this->menu->add_option(
		"�Q�[�����I���",
		[this](
			shared_ptr<ApplicationMain> application_main,
			shared_ptr<Scene> scene)->shared_ptr<Scene> {
		application_main->set_quit(true);
		return shared_from_this();
	}
	);
}
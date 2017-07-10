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
	/*TODO:設定ファイルやコンフィグファイルから設定を読み込み
	メンバ変数に値をセットする*/
	this->title_text = ConstValues::get_instance().get_title();
	this->cursol = "■";
	this->menu = make_shared<Select>();
	this->menu->set_cycle_flag(true);
	this->menu->set_coord(240, 360);
	this->menu->set_font_size(16);
	this->menu->add_option(
		"ひとりで遊ぶ",
		[this](
			shared_ptr<ApplicationMain> application_main,
			shared_ptr<Scene> scene)->shared_ptr<Scene> {
		//TODO:ひとりプレイ用ゲーム画面へ飛ぶ処理をする。
		return shared_from_this();
	});
	this->menu->add_option(
		"通信対戦で遊ぶ",
		[this](
			shared_ptr<ApplicationMain> application_main,
			shared_ptr<Scene> scene)->shared_ptr<Scene> {
		//TODO:対戦相手を探す画面へ飛ぶ処理をする。
		return shared_from_this();
	}
	);
	this->menu->add_option(
		"ゲームを終わる",
		[this](
			shared_ptr<ApplicationMain> application_main,
			shared_ptr<Scene> scene)->shared_ptr<Scene> {
		application_main->set_quit(true);
		return shared_from_this();
	}
	);
}
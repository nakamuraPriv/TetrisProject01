#include "DxLib.h"
#include "application_main.h"
#include "keyboard.h"
#include "inputs.h"
#include <memory>

using namespace std;

int WINAPI WinMain(HINSTANCE hInstancs, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int num) {
	if (ChangeWindowMode(TRUE) != 0 ||
		SetWindowText("TETRIS!!") != 0 ||
		DxLib_Init() != 0 ||
		SetDrawScreen(DX_SCREEN_BACK) != 0) {
		return -1;
	}

	shared_ptr<ApplicationMain> application_main = make_shared<ApplicationMain>();
	shared_ptr<Inputs> inputs = make_shared<Inputs>();
	application_main->set_inputs(inputs);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		application_main->run();
		if (application_main->is_quit()) {
			break;
		}
	}

	DxLib_End();
	return 0;
}
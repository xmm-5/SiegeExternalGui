#include "gui.h"
#include "recoil.h"

#include <thread>

// add more features like custom keybinds, raping black children, fuck pride month

Values values;

int __stdcall wWinMain(
	HINSTANCE instance,
	HINSTANCE previousInstance,
	PWSTR arguments,
	int commandShow)
{

	gui::CreateHWindow("Global External", "Yapp yapp");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::exit)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));

		gui::BeginRender();
		gui::Render();
		gui::EndRender();
		if (GetAsyncKeyState('1') & 0x8000)
			values.toggle = true;

		if (GetAsyncKeyState('2') & 0x8000)
			values.toggle = false;

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000 && values.toggle)
			MoveMouse(values.recoil);
	}

	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();
	return EXIT_SUCCESS;
}
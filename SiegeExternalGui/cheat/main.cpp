#include "gui.h"
#include "recoil.h"

#include <thread>

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

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000)
			MoveMouse(values.recoil);
	}

	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();
	return EXIT_SUCCESS;
}
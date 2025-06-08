#include "recoil.h"

void MoveMouse(int recoil)
{
	mouse_event(MOUSEEVENTF_MOVE, 0, recoil, 0, 0);
}
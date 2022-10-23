#include "Snake.h"
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Xinput.lib")
#pragma comment(lib, "OpenAL32.lib")
int main()
{
	idAnimationRegister::LoadAllAnimations(POSITION_ANIMATIONS_FILE, FRAME_ANIMATIONS_FILE);
	idSnake game;
	game.Start();
}
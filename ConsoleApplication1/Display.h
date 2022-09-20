#pragma once
#include <windows.h>
#include <iostream>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 40
class Display
{
private:
	CHAR_INFO* buffer;
	HANDLE hOutput;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;
public:
	Display();
	void DrawPixel(int x, int y, int color);
	void Refresh();
};

#pragma once
#include <windows.h>
#include <iostream>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 40
#define UI_HEIGHT 8
#define BLACK 0x0
#define DARK_BLUE 0x1
#define DARK_GREEN 0x2
#define DARK_CYAN 0x3
#define DARK_RED 0x4
#define DARK_PURPLE 0x5
#define DARK_YELLOW 0x6
#define GRAY 0x7
#define DARK_GRAY 0x8
#define BLUE 0x9
#define GREEN 0xA
#define CYAN 0xB
#define RED 0xC
#define PURPLE 0xD
#define YELLOW 0xE
#define WHITE 0xF

class idDisplay
{
private:
	CHAR_INFO* buffer;
	HANDLE hOutput;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;
public:
	idDisplay();
	void DrawPixel(int x, int y, int color);
	void Refresh();
	void Fill(int color);
};

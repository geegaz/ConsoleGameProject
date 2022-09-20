#pragma once
#include <windows.h>
#include <iostream>
class Display
{
private:
	CHAR_INFO* buffer;
public:
	int width, height;
	Display(CHAR_INFO*&, int width, int height);
	void Draw(int x, int y, int color);
};

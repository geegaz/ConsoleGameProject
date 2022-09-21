#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Display.h"

using namespace std;

class Sprite
{
private:
	int* data;
	int sizeX, sizeY;

public:
	Sprite();
	Sprite(string);
	Sprite(int, int, int);
	Sprite& operator=(Sprite& other);

	~Sprite();
	int Draw(Display& display, int x, int y);

};


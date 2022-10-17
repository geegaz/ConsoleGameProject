#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Display.h"

using namespace std;

struct idSprite
{
public:
	int* data;
	int sizeX, sizeY;
	int framesX, framesY;

	idSprite();
	idSprite(string);
	idSprite(int, int, int);

	~idSprite();
	void Draw(idDisplay& display, int x, int y, int frame = 0);
};


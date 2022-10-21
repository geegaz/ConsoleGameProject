#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Display.h"
#include "Vector2D.h"

using namespace std;

struct idSprite
{
public:
	int* data;
	intVector2_t size;
	intVector2_t frames;

	idSprite();
	idSprite(string);
	idSprite(int, int, int);

	~idSprite();
	void Draw(idDisplay& display, int x, int y, int frame = 0);
};


#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Display.h"
#define TOP_MASK 0b00001111
#define BOTTOM_MASK 0b11110000

using namespace std;

class Sprite
{
private:
	int* data;
	int sizeX, sizeY;

public:
	Sprite();
	Sprite(ifstream&);
	Sprite(int, int, int);
	Sprite& operator=(Sprite& other);

	~Sprite();
	int Draw(Display& display, int x, int y);

};


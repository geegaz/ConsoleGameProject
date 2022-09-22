#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "idDisplay.h"

using namespace std;

class idSprite
{
private:
	int* data;
	int sizeX, sizeY;
	int framesX, framesY;

public:
	idSprite();
	idSprite(string);
	idSprite(int, int, int);
	idSprite& operator=(idSprite& other);

	~idSprite();
	void Draw(idDisplay& display, int x, int y, int frame = 0);

};


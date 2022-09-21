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

public:
	idSprite();
	idSprite(string);
	idSprite(int, int, int);
	idSprite& operator=(idSprite& other);

	~idSprite();
	int Draw(idDisplay& display, int x, int y);

};


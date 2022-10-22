#pragma once
#include <string>
#include "Sprite.h"
#include "Display.h"
#include "SpriteRenderer.h"
using namespace std;

class idNumberDisplay
{
private:
	static idSprite NUMBERS_SPRITE;
	idStaticSpriteRenderer renderer;
	int digits;
	intVector2_t position;
public:
	idNumberDisplay(int _digits, int x, int y);
	~idNumberDisplay();
	void Draw(idDisplay& display, int value);
};


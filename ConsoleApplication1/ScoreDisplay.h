#pragma once
#include <string>
#include "Sprite.h"
#include "Display.h"
#include "SpriteRenderer.h"
using namespace std;

class idScoreDisplay
{
private:
	static idSprite NUMBERS_SPRITE;
	idStaticSpriteRenderer renderer;
public:
	idScoreDisplay();
	~idScoreDisplay();
	void Draw(idDisplay& display, int score, int digits = 3);
};


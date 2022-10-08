#pragma once
#include <string>
#include "Sprite.h"
#include "Display.h"

using namespace std;

class idScoreDisplay
{
private:
	idSprite numbersSprite;
public:
	idScoreDisplay(idSprite& numbers);
	~idScoreDisplay();
	void Draw(idDisplay& display, int score, int digits = 3);
};


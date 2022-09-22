#pragma once
#include <string>
#include "idSprite.h"
#include "idDisplay.h"

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


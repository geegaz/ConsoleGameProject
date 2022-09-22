#pragma once
#include <string>
#include "idSprite.h"
#include "idDisplay.h"

using namespace std;

class idScoreDisplay
{
private:
	idSprite sprite;
public:
	idScoreDisplay();
	~idScoreDisplay();
	void Draw(idDisplay& display, int score, int digits = 3);
};


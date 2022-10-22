#include "ScoreDisplay.h"

idSprite idScoreDisplay::NUMBERS_SPRITE("resources\\sprites\\Numbers.txt");
idScoreDisplay::idScoreDisplay(): renderer(NUMBERS_SPRITE){}

idScoreDisplay::~idScoreDisplay() {}

void idScoreDisplay::Draw(idDisplay& display, int score, int digits) {
	int value = score;
	
	for (int i = 0; i < digits; i++) {
		renderer.Draw(display, intVector2_t(4 *(digits - i - 1), 1), value % 10);
		value /= 10;
	}
}
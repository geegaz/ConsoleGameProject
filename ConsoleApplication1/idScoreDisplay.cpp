#include "idScoreDisplay.h"

idScoreDisplay::idScoreDisplay(idSprite& numbers): numbersSprite(numbers) {}

idScoreDisplay::~idScoreDisplay() {}

void idScoreDisplay::Draw(idDisplay& display, int score, int digits) {
	int value = score;
	
	for (int i = 0; i < digits; i++) {
		numbersSprite.Draw(display, 2 + 4 *(digits - i - 1), 1, value % 10);
		value /= 10;
	}
}
#include "idScoreDisplay.h"

idScoreDisplay::idScoreDisplay(idSprite& numbers): numbersSprite(numbers) {}

idScoreDisplay::~idScoreDisplay() {}

void idScoreDisplay::Draw(idDisplay& display, int score, int digits) {
	int multiplier = 1;
	int digit_value = 0;
	
	for (int i = 0; i < digits; i++) {
		multiplier *= 10;
		digit_value = score % multiplier - digit_value;

		numbersSprite.Draw(display, 2 + 4 * (digits - i), 1, digit_value);
	}
}
#include "idScoreDisplay.h"

idScoreDisplay::idScoreDisplay(): sprite(".\\resources\\sprites\\Numbers.txt")) {
}

idScoreDisplay::~idScoreDisplay() {}

void idScoreDisplay::Draw(idDisplay& display, int score, int digits) {
	int digit_value = 0;
	int multiplier = 1;
	for (int i = digits - 1; i >= 0; i--) {
		multiplier *= 10;
		digit_value = score % multiplier - digit_value;

		sprite.Draw(display, 2 + 4 * i, 1, digit_value);
	}
}
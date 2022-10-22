#include "NumberDisplay.h"

idSprite idNumberDisplay::NUMBERS_SPRITE("resources\\sprites\\Numbers.txt");
idNumberDisplay::idNumberDisplay(int _digits, int x, int y) : renderer(NUMBERS_SPRITE), digits(_digits), position(x,y){}

idNumberDisplay::~idNumberDisplay() {}

void idNumberDisplay::Draw(idDisplay& display, int value) {
	int val = value;
	
	for (int i = 0; i < digits; i++) {
		renderer.Draw(display, position + intVector2_t(4 *(digits - i - 1), 0), val % 10);
		val /= 10;
	}
}
#include "Mario.h"
idMarioState::idMarioState() : big(false), fire(false) {}

bool idMarioState::IsBig() {
	return big;
}

bool idMarioState::IsFire() {
	return fire;
}

bool idMarioState::PowerUp() {
	if (!big) {
		big = true;
		return true;
	}
	if (!fire) {
		fire = true;
		return true;
	}
	return false;
}

bool idMarioState::PowerDown() {
	if (fire) {
		fire = false;
		return true;
	}
	if (big) {
		big = false;
		return true;
	}
	return false;
}

void idMarioState::Reset() {
	big = false;
	fire = false;
}

#include "LevelDisplayer.h"
idLevelDisplayer::idLevelDisplayer(idDisplay& _display) :camera(0, 0), display(_display) {}

intVector2_t idLevelDisplayer::GetRelativeCoords(intVector2_t worldCoords) {
	return worldCoords - camera;
}

void idLevelDisplayer::MoveCameraIfNeeded() {
	//camera.x += 1;
}

bool idLevelDisplayer::InBounds(intVector2_t coords, intVector2_t size) {
	intVector2_t top_left = GetRelativeCoords(coords);
	intVector2_t bottom_right = GetRelativeCoords(coords + size);
	
	if (bottom_right.x <= 0 || bottom_right.y <= 0)
		return false;
	if (top_left.x >= SCREEN_WIDTH || top_left.y >= SCREEN_HEIGHT*2)
		return false;
	return true;
}
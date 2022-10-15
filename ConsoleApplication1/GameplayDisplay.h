#pragma once
#include "Display.h"
#include "Vector2D.h"
#include "Sprite.h"
class idGameplayDisplay
{
private:
	intVector2_t camera; // top left corner of camera
	idDisplay& display;
public:
	
	idGameplayDisplay(idDisplay& _display);
	void MoveCameraIfNeeded();
	void Draw();
	bool InBounds(intVector2_t coords, intVector2_t size);
	intVector2_t GetRelativeCoords(intVector2_t worldCoords);
	void GetCameraCorners(intVector2_t out[]);
};
#pragma once
#include <map>
#include "Display.h"
#include "Vector2D.h"
#include "SpriteRenderer.h"
#include "LevelObject.h"
class idLevelDisplayer
{
private:
	intVector2_t camera; // top left corner of camera
	idDisplay& display;
	idLevelObject& cameraTarget;
public:
	idLevelDisplayer(idDisplay& _display, idLevelObject& _cameraTarget);
	void MoveCameraIfNeeded();
	void DrawLevel(std::map<int, idSpriteRenderer> level); // level = any object with collision
	void DrawParticles(std::vector<idSpriteRenderer> particles);
	bool InBounds(intVector2_t coords, intVector2_t size);
	intVector2_t GetRelativeCoords(intVector2_t worldCoords);
	void GetCameraCorners(intVector2_t out[]);
};
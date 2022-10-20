#pragma once
#include <windows.h>
#include "Collider.h"
#include "Display.h"
#include "ScoreDisplay.h"
#include "ControlsManager.h"

class idPhysicsTest
{
private:
	idDisplay& display;
	idControlsManager& controls;
	
	idSprite ballSprite;
	idCollider ballCollider;

	idScoreDisplay score;

	idSprite bottomBoundSprite;
	idSprite leftBoundSprite;
	idSprite rightBoundSprite;
	idCollider bottomBoundCollider;
	idCollider leftBoundCollider;
	idCollider rightBoundCollider;

	floatVector2_t bottomBoundPosition;
	floatVector2_t leftBoundPosition;
	floatVector2_t rightBoundPosition;
	floatVector2_t position;
	floatVector2_t velocity;
	bool onGround;

	bool Move(floatVector2_t vel, float delta, int tries = 4);
public:
	float gravity;
	float pushForce;
	float bounciness;
	float friction;

	idPhysicsTest(idDisplay& displ, idControlsManager& in);
	void Update(float delta);
	void Jump();
	void Dash(int dir);
};


#pragma once
#include <windows.h>
#include "Collider.h"
#include "Display.h"
#include "ControlsManager.h"

class idPhysicsTest
{
private:
	idDisplay& display;
	idControlsManager& controls;
	
	idSprite ballSprite;
	idCollider ballCollider;
	idCollider bounds;

	floatVector2_t boundsPosition;
	floatVector2_t position;
	floatVector2_t velocity;
	bool onGround;

	bool Move(floatVector2_t vel, collision_t& col, int tries);
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


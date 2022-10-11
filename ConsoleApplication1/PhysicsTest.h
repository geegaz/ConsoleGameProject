#pragma once
#include <windows.h>
#include "Display.h"
#include "ControlsManager.h"

typedef struct {
	int dirX;
	int dirY;
} collision_t;

class idPhysicsTest
{
private:
	idDisplay& display;
	idControlsManager& controls;
	idSprite ballSprite;
	float posX, posY;
	float velX, velY;
	bool onGround;

	bool Move(float vel_x, float vel_y, collision_t& col);
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


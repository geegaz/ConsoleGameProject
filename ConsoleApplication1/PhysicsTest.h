#pragma once
#include <windows.h>
#include "Display.h"
#include "InputManager.h"

typedef struct {
	int dirX;
	int dirY;
} collision_t;

class idPhysicsTest
{
private:
	idDisplay& display;
	idInputManager& input;
	float posX, posY;
	float velX, velY;
	bool onGround;

	bool Move(float vel_x, float vel_y, collision_t& col);
public:
	float gravity;
	float pushForce;
	float bounciness;

	idPhysicsTest(idDisplay& displ, idInputManager& in);
	void Update(float delta);
	void Jump();
	void Dash(float dir);
};


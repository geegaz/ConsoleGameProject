#pragma once
#include <windows.h>
#include "Display.h"

typedef struct {
	

} collision;

class idPhysicsTest
{
private:
	idDisplay& display;
	float posX, posY;
	float velX, velY;

	collision Collide(float vel_x, float vel_y);
public:
	float gravity;
	float pushForce;

	idPhysicsTest(idDisplay& displ);
	void Update(float delta);
};


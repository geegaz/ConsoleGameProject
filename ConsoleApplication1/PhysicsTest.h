#pragma once
#include <windows.h>
#include "idDisplay.h"

typedef struct {
	bool collide;
} collision;

class idPhysicsTest
{
private:
	idDisplay& display;
	float posX, posY;
	float velX, velY;

	bool Move();
public:
	float gravity;
	float pushForce;

	idPhysicsTest(idDisplay& displ);
	void Update(float delta);
};


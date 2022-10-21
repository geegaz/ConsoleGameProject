#pragma once
#include "LevelObject.h"

class idBouncingBall :
    public idLevelObject
{
private:
	bool onGround;
public:
	float gravity;
	float pushForce;
	float bounciness;
	float friction;

	void Move(floatVector2_t vel, float delta);
};


#pragma once
#include "Vector2D.h"
#include "Display.h"
class idParticle
{
protected:
	floatVector2_t position;
	int lifespan;
	int life;
public:
	idParticle(int x, int y, int _lifespan);
	virtual void Update();
	virtual void Draw(idDisplay& display) = 0;
	virtual ~idParticle();
	bool IsDead();
};


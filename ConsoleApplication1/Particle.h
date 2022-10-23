#pragma once
#include "SpriteRenderer.h"
#include "Vector2D.h"
class idParticle
{
protected:
	idSpriteRenderer spriteRenderer;
	idAnimationRegister animationRegister;
	floatVector2_t position;
	int lifespan;
	int life;
public:
	idParticle(int x, int y, idSprite& sprite, int _lifespan, intVector2_t spriteOffset = intVector2_t(0, 0));
	virtual void Update();
	idSpriteRenderer& GetRenderer();
	virtual ~idParticle();
	bool IsDead();
};


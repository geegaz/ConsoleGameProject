#pragma once
#include "Particle.h"
#include "SpriteRenderer.h"
class idEffectParticle :public idParticle {
protected:
	idSpriteRenderer spriteRenderer;
	int frameLength;
	int frameTimer;
public:
	idEffectParticle(int x, int y, int _lifespan, idSprite& sprite, int _frameLength = 1, std::string positionAnimation = "",
		std::string frameAnimation = "", intVector2_t spriteOffset = intVector2_t(0, 0));
	virtual void Update();
	virtual void Draw(idDisplay& display);
};

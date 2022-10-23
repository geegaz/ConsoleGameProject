#pragma once
#include "GameConstants.h"
#include "Particle.h"
class idAppleCollectEffect:public idParticle
{
private:
	static idSprite APPLE_COLLECT_FRAMES;
	static idAnimationRegister APPLE_COLLECT_REGISTER;
	int timer;
public:
	idAppleCollectEffect(int x, int y);
	void virtual Update();
};


#include "EffectParticle.h"

idEffectParticle::idEffectParticle(int x, int y, int _lifespan, idSprite& sprite, int _frameLength, std::string positionAnimation,
	std::string frameAnimation, intVector2_t spriteOffset) :
	idParticle(x, y, _lifespan), spriteRenderer(sprite, startPosition, positionAnimation, frameAnimation, spriteOffset),
	frameTimer(0), frameLength(_frameLength) {}

void idEffectParticle::Update() {
	if (frameTimer % frameLength == 0) {
		idParticle::Update();
		spriteRenderer.NextFrame();
		spriteRenderer.NextPosition();
	}
	frameTimer++;
}



void idEffectParticle::Draw(idDisplay& display) {
	spriteRenderer.Draw(display);
}
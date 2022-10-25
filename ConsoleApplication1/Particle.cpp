#include "Particle.h"

idParticle::idParticle(int x, int y, idSprite& sprite, int _lifespan,
	std::string positionAnimation, std::string frameAnimation, intVector2_t spriteOffset)
	:position(x, y), spriteRenderer(sprite, position, positionAnimation, frameAnimation, spriteOffset), lifespan(_lifespan), life(0) {}

idParticle::~idParticle() {}

void idParticle::Update() {
	spriteRenderer.NextFrame();
	spriteRenderer.NextPosition();
	life++;
}

idSpriteRenderer& idParticle::GetRenderer() {
	return spriteRenderer;
}

bool idParticle::IsDead(){
	return life >= lifespan;
}
#include "Particle.h"

idParticle::idParticle(int x, int y, int _lifespan)
	:position(x, y), lifespan(_lifespan), life(0) {}

idParticle::~idParticle() {}

void idParticle::Update() {
	life++;
}

bool idParticle::IsDead(){
	return life >= lifespan;
}
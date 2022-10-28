#include "ParticlesManager.h"
#include "EffectParticle.h"

idParticlesManager::idParticlesManager(){}
void idParticlesManager::UpdateParticles() {
	int size = particles.size();
	idParticle* mid;
	for (int i = 0; i<size ; i++) {
		particles[i]->Update();
		if (particles[i]->IsDead()) {
			mid = particles[i];
			particles[i] = particles.back();
			delete mid;
			particles.pop_back();
			size--;
			i--;
		}	
	}
}
void idParticlesManager::DrawParticles(idDisplay display) {
	int size = particles.size();
	for (int i = 0; i < size; i++) {
		particles[i]->Draw(display);
	}
}
void idParticlesManager::CreateAppleCollectEffect(int x, int y) {
	static idSprite APPLE_COLLECT_FRAMES(SPRITES_PATH + "apple_pop.txt");
	particles.push_back(new idEffectParticle(x, y, 20, APPLE_COLLECT_FRAMES, 2, "apple.collect", "apple.collect", intVector2_t(-2, -1)));
}

void idParticlesManager::Clear() {
	for (int i = particles.size()-1; i >= 0 ; i--) {
		delete particles[i];
		particles.pop_back();
	}
}

void idParticlesManager::CreateDeathParticles(int x, int y, int count) {
	static idSprite SHATTER_PARTICLES(SPRITES_PATH + "shatter_particles.txt");
	for (int i = 0; i < count; i++) {
		particles.push_back(new idEffectParticle(x, y, 3, SHATTER_PARTICLES));
	}
}

idParticlesManager::~idParticlesManager() {
	Clear();
}
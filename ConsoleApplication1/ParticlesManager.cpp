#include "ParticlesManager.h"
#include "AppleCollectEffect.h"
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
		particles[i]->GetRenderer().Draw(display);
	}
}
void idParticlesManager::CreateAppleCollectEffect(int x, int y) {
	particles.push_back(new idAppleCollectEffect(x,y));
}

idParticlesManager::~idParticlesManager() {
	for (int i = 0; i < particles.size(); i++) {
		delete particles[i];
	}
}
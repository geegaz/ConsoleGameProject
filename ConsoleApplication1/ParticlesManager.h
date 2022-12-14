#pragma once
#include "Particle.h"
#include "Display.h"
#include <vector>
class idParticlesManager
{
private:
	std::vector<idParticle*> particles;
public:
	idParticlesManager();
	void UpdateParticles();
	void DrawParticles(idDisplay display);
	void CreateAppleCollectEffect(int x, int y);
	void CreateDeathParticles(int x, int y, int count);
	void Clear();
	~idParticlesManager();
};


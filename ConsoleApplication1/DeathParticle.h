#pragma once
#include "Particle.h"

class idDeathParticle :
    public idParticle
{
private:
    floatVector2_t velocity;
    int frame;
public:
    idDeathParticle(int x, int y, int _lifespan);
    void Update();
    void Draw(idDisplay& display);
};


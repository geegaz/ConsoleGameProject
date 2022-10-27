#pragma once
#include "Particle.h"
#include "Sprite.h"
#include <random>
#define PI 3.141592

class idDeathParticle :
    public idParticle
{
private:
    floatVector2_t velocity;
    idSprite& sprite;
    int frame;
public:
    idDeathParticle(int x, int y, int _lifespan, idSprite& _sprite);
    void Update();
    void Draw(idDisplay& display);
};


#pragma once
#include "Particle.h"
#include "Sprite.h"
#include <random>
#define PI 3.141592

class idDeathParticle :
    public idParticle
{
private:
    static idSprite SPRITE;

    floatVector2_t velocity;
    int frame;
    float timer;
public:
    idDeathParticle(int x, int y, int _lifespan);
    void Update();
    void Draw(idDisplay& display);
};


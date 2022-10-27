#include "DeathParticle.h"

extern float delta_time;

idDeathParticle::idDeathParticle(int x, int y, int _lifespan, idSprite& _sprite)
	:idParticle(x, y, _lifespan), sprite(_sprite), timer(0.0f)
{
	float pi = 3.141592;
	float angle = ((float)rand() / (RAND_MAX)) * 2*pi;
	frame = rand() % (sprite.frames.x * sprite.frames.y);
	velocity.x = cosf(angle) * 10.0f;
	velocity.y = sinf(angle) * 10.0f;
}

void idDeathParticle::Update() {
	position += velocity * delta_time;
	timer += delta_time;
}

void idDeathParticle::Draw(idDisplay& display) {
	sprite.Draw(display, position.x, position.y, frame);
}

bool idDeathParticle::IsDead() {
	return timer > (float)lifespan;
}
#include "DeathParticle.h"

extern float delta_time;

idDeathParticle::idDeathParticle(int x, int y, int _lifespan, idSprite& _sprite)
	:idParticle(x, y, _lifespan), sprite(_sprite)
{
	float angle = ((float)rand() / (RAND_MAX)) * PI;
	frame = rand()% (sprite.frames.x * sprite.frames.y);
	velocity = floatVector2_t(
		cosf(angle),
		sinf(angle)
	) * 20.0f;
}

void idDeathParticle::Update() {
	position += velocity * delta_time;
}

void idDeathParticle::Draw(idDisplay& display) {
	sprite.Draw(display, position.x, position.y, frame);
}
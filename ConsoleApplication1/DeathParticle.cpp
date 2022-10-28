#include "DeathParticle.h"

extern float delta_time;

idSprite idDeathParticle::SPRITE("resources\\sprites\\shatter_particles.txt");

idDeathParticle::idDeathParticle(int x, int y, int _lifespan)
	:idParticle(x, y, _lifespan), timer(0.0f)
{
	float pi = 3.141592;
	float angle = ((float)rand() / (RAND_MAX)) * 2*pi;
	frame = rand() % (SPRITE.frames.x * SPRITE.frames.y);
	velocity.x = cosf(angle) * 40.0f;
	velocity.y = sinf(angle) * 40.0f - 20.0f;
}

void idDeathParticle::Update() {
	velocity.y += 60.0f * delta_time;
	velocity.x *= 0.99f;
	velocity.y *= 0.99f;
	position += velocity * delta_time;
	timer += delta_time;

	if (timer > lifespan) {
		life = lifespan;
	}
}

void idDeathParticle::Draw(idDisplay& display) {
	SPRITE.Draw(display, position.x, position.y, frame);
}
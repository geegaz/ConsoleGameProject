#include "PhysicsTest.h"

idPhysicsTest::idPhysicsTest(idDisplay& displ, idInputManager& in): 
	display(displ),
	input(in),
	posX(10.0f), posY(10.0f),
	velX(20.0f), velY(20.0f),
	gravity(40.0f),
	pushForce(25.0f),
	bounciness(0.8f),
	onGround(false)
	{}

void idPhysicsTest::Update(float delta) {
	
	velY += gravity * delta;

	collision_t col;
	if (Move(velX * delta, velY * delta, col)) {
		if (col.dirX != 0) velX = -velX * bounciness;
		if (col.dirY != 0) velY = -velY * bounciness;
	}
	display.DrawPixel(posX, posY, WHITE);
}

bool idPhysicsTest::Move(float vel_x, float vel_y, collision_t& col) {
	bool collided(false);

	posX += vel_x;
	posY += vel_y;

	col.dirX = 0;
	col.dirY = 0;
	
	if (posX > SCREEN_WIDTH) {
		posX = SCREEN_WIDTH;
		collided = true;
		col.dirX = 1;
	}
	else if (posX < 0) {
		posX = 0;
		collided = true;
		col.dirX = -1;
	}
	if (posY > SCREEN_HEIGHT * 2) {
		posY = SCREEN_HEIGHT * 2;
		collided = true;
		col.dirY = 1;

		onGround = true;
	}
	else if (posY < 0) {
		posY = 0;
		collided = true;
		col.dirY = -1;
	}

	return collided;
}

void idPhysicsTest::Jump() {
	velY -= gravity * 2 * pushForce;
}

void idPhysicsTest::Dash(float dir) {
	velX += dir * pushForce;
}
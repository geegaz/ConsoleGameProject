#include "PhysicsTest.h"

idPhysicsTest::idPhysicsTest(idDisplay& displ, idControlsManager& in) :
	display(displ),
	controls(in),
	ballSprite("resources\\sprites\\Sprite.txt")
{

	posX = 10.0f;
	posY = 10.0f;
	velX = 25.0f;
	velY = 20.0f;

	gravity = 40.0f;
	pushForce = 25.0f;
	bounciness = 0.95f;
	friction = 0.15f;

	onGround = false;
}

void idPhysicsTest::Update(float delta) {
	
	velY += gravity * delta;

	if (onGround && controls.GetControlState(control_t::UP).pressed) {
		Jump();
		onGround = false;
	}
	if (controls.GetControlState(control_t::LEFT).justPressed) {
		Dash(-1);
	}
	if (controls.GetControlState(control_t::RIGHT).justPressed) {
		Dash(1);
	}

	collision_t col;
	if (Move(velX * delta, velY * delta, col)) {
		if (col.dirX != 0) velX = -velX * bounciness;
		if (col.dirY != 0) velY = -velY * bounciness;
	}


	//-- Smoothed 
	int x, y;
	if (abs(velX) > abs(velY)) {
		x = round(posX);
		y = round(posY + (x - posX) * velY / velX);
	}
	else {
		y = round(posY);
		x = round(posX + (y - posY) * velX / velY);
	}
	
	ballSprite.Draw(display, x - 4, y - 4);
}

bool idPhysicsTest::Move(float vel_x, float vel_y, collision_t& col) {
	bool collided(false);

	posX += vel_x;
	posY += vel_y;

	col.dirX = 0;
	col.dirY = 0;
	
	if (posX > SCREEN_WIDTH - 1) {
		posX = SCREEN_WIDTH - 1;
		collided = true;
		col.dirX = 1;
	}
	else if (posX < 0) {
		posX = 0;
		collided = true;
		col.dirX = -1;
	}
	if (posY > SCREEN_HEIGHT * 2 - 1) {
		posY = SCREEN_HEIGHT * 2 - 1;
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
	velY = -gravity;
}

void idPhysicsTest::Dash(int dir) {
	velX += dir * pushForce;
}
#include "PhysicsTest.h"

idPhysicsTest::idPhysicsTest(idDisplay& displ, idControlsManager& in) :
	display(displ),
	controls(in),

	ballSprite("resources/sprites/Sprite.txt"),
	ballCollider(position, 8.0f, 8.0f),
	boundSprite(BLUE, (float)SCREEN_WIDTH, 8.0f),
	boundCollider(boundPosition, (float)SCREEN_WIDTH, 8.0f)
{
	boundPosition.y = (float)SCREEN_HEIGHT * 2.0f - 10.0f;
	
	position.x = 10.0f;
	position.y = 10.0f;
	velocity.x = 25.0f;
	
	gravity = 40.0f;
	pushForce = 25.0f;
	bounciness = 0.95f;
	friction = 0.15f;

	onGround = false;
}

void idPhysicsTest::Update(float delta) {
	
	velocity.y += gravity * delta;

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

	Move(velocity, delta);

	//-- Smoothed 
	int x, y;
	/*if (abs(velocity.x) > abs(velocity.y)) {
		x = round(position.x);
		y = round(position.y + (x - position.x) * velocity.y / velocity.x);
	}
	else {
		y = round(position.y);
		x = round(position.x + (y - position.y) * velocity.x / velocity.y);
	}*/
	x = position.x;
	y = position.y;
	
	boundSprite.Draw(display, boundPosition.x, boundPosition.y);
	ballSprite.Draw(display, x, y);
}

bool idPhysicsTest::Move(floatVector2_t vel, float delta, int tries) {
	vel.x *= delta;
	vel.y *= delta;
	position += vel;

	collision_t col;
	if (idCollider::Collide(ballCollider, boundCollider, col)) {
		if (abs(col.normal.y) > 0.0f) {
			position.y -= vel.y;
			velocity.y = 0.0f;
		}
		if (abs(col.normal.x) > 0.0f) {
			position.x -= vel.x;
			velocity.x = 0.0f;
		}

		// TODO: Ball gets stuck in collider (and clips through it)
		// Idea: position ball to collision surface

		if (col.normal.y < 0.0f) {
			onGround = true;
		}
	}

	return false;
}

void idPhysicsTest::Jump() {
	velocity.y = -gravity;
}

void idPhysicsTest::Dash(int dir) {
	velocity.x += dir * pushForce;
}
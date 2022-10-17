#include "PhysicsTest.h"

idPhysicsTest::idPhysicsTest(idDisplay& displ, idControlsManager& in) :
	display(displ),
	controls(in),
	
	ballCollider(position, 8.0f, 8.0f),
	bounds(boundsPosition, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT * 2)
{
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

	collision_t col;
	if (Move(velocity, col, delta)) {
		
	}


	//-- Smoothed 
	int x, y;
	if (abs(velocity.x) > abs(velocity.y)) {
		x = round(position.x);
		y = round(position.y + (x - position.x) * velocity.y / velocity.x);
	}
	else {
		y = round(position.y);
		x = round(position.x + (y - position.y) * velocity.x / velocity.y);
	}
	
	ballSprite.Draw(display, x, y);
}

bool idPhysicsTest::Move(floatVector2_t vel, collision_t& col, float delta, int tries) {
	vel.x *= delta;
	vel.y *= delta;
	position += vel;

	/*int tried = 0;
	while (idCollider::CollideBounds(ballCollider, bounds) || tried > tries) {

		tried++;
	}*/
	if (idCollider::CollideBounds(ballCollider, bounds)) position -= vel;

	return false;
}

void idPhysicsTest::Jump() {
	velocity.y = -gravity;
}

void idPhysicsTest::Dash(int dir) {
	velocity.x += dir * pushForce;
}
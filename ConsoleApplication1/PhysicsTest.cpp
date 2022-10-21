#include "PhysicsTest.h"

idPhysicsTest::idPhysicsTest(idDisplay& displ, idControlsManager& in) :
	display(displ),
	controls(in),

	ballSprite("resources/sprites/Sprite.txt"),
	ballCollider(position, 8.0f, 8.0f),
	
	bottomBoundSprite(BLUE, (float)SCREEN_WIDTH, 8.0f),
	bottomBoundCollider(bottomBoundPosition, (float)SCREEN_WIDTH, 8.0f),
	leftBoundSprite(BLUE, 8.0f, (float)SCREEN_HEIGHT * 2.0f),
	leftBoundCollider(leftBoundPosition, 8.0f, (float)SCREEN_HEIGHT * 2.0f),
	rightBoundSprite(BLUE, 8.0f, (float)SCREEN_HEIGHT * 2.0f),
	rightBoundCollider(rightBoundPosition, 8.0f, (float)SCREEN_HEIGHT * 2.0f)
{
	bottomBoundPosition.y = (float)SCREEN_HEIGHT * 2.0f - 8.0f;
	leftBoundPosition.x = 0.0f;
	rightBoundPosition.x = (float)SCREEN_WIDTH - 8.0f;
	
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

	float dir = 0.0f;
	if (controls.GetControlState(control_t::LEFT).pressed) {
		dir = -1.0f;
	}
	if (controls.GetControlState(control_t::RIGHT).pressed) {
		dir = 1.0f;
	}
	velocity.x = dir * 25.0f;

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
	
	bottomBoundSprite.Draw(display, bottomBoundPosition.x, bottomBoundPosition.y);
	leftBoundSprite.Draw(display, leftBoundPosition.x, leftBoundPosition.y);
	rightBoundSprite.Draw(display, rightBoundPosition.x, rightBoundPosition.y);
	
	ballSprite.Draw(display, x, y);
	score.Draw(display, idCollider::registeredIDs);
}

bool idPhysicsTest::Move(floatVector2_t vel, float delta, int tries) {
	vel.x *= delta;
	vel.y *= delta;
	position += vel;

	collision_t col;
	auto it = idCollider::registeredColliders.begin();
	auto end = idCollider::registeredColliders.end();
	while (it != end) {
		if ((*it).first != ballCollider.colliderID && idCollider::Collide(ballCollider, *(*it).second, col)) {

			display.Fill(GREEN);

			position += col.normal * col.depth;
			if (abs(col.normal.y) > 0.0f) {
				velocity.y = 0.0f;
			}
			if (abs(col.normal.x) > 0.0f) {
				velocity.x = 0.0f;
			}

			// Ground handling
			if (col.normal.y < 0.0f) {
				onGround = true;
			}
		}
		it++;
	}

	return false;
}

void idPhysicsTest::Jump() {
	velocity.y = -gravity;
}
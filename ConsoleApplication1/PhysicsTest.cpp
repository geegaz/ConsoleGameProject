#include "PhysicsTest.h"

idPhysicsTest::idPhysicsTest(idDisplay& displ): 
	display(displ),
	posX(0.0f), posY(0.0f),
	velX(1.0f), velY(1.0f),
	gravity(10.0f),
	pushForce(25.0f)
	{}

void idPhysicsTest::Update(float delta) {
	

	velY += gravity * delta;

	display.DrawPixel(posX, posY, WHITE);
}

bool idPhysicsTest::Move() {
	bool collided(false);

	posX += velX;
	posY += velY;
	
	if (posX > SCREEN_WIDTH) {
	}


	return collided;
}
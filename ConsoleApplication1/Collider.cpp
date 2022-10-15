#include "Collider.h"


int idCollider::registeredIDs = 0;

idCollider::idCollider() : colliderRect(rect_t()) {
	colliderRect.x = 0.0f;
	colliderRect.y = 0.0f;
	colliderRect.w = 1.0f;
	colliderRect.h = 1.0f;

	RegisterCollider();
}

idCollider::idCollider(rect_t& rect) {
	colliderRect = rect;

	RegisterCollider();
}

idCollider::idCollider(float x, float y, float w, float h) : colliderRect(rect_t()) {
	colliderRect.x = x;
	colliderRect.y = y;
	colliderRect.w = w;
	colliderRect.h = h;

	RegisterCollider();
}

idCollider::~idCollider() {
	registeredColliders.
}

void idCollider::RegisterCollider() {
	colliderID = idCollider::registeredIDs;
	idCollider::registeredIDs++;
}

bool idCollider::Collide(idCollider& a, idCollider& b) {
	return (
		a.colliderRect.x < b.colliderRect.x + b.colliderRect.w &&
		a.colliderRect.x + a.colliderRect.w > b.colliderRect.x &&
		a.colliderRect.y < b.colliderRect.y + b.colliderRect.h &&
		a.colliderRect.h + a.colliderRect.y > b.colliderRect.y
	);
}
#include "Collider.h"


int idCollider::registeredIDs = 0;
map<int, idCollider*> idCollider::registeredColliders;

idCollider::idCollider(floatVector2_t& _position, floatVector2_t _size, int _mask, int _interactionMask)
	: position(_position),size(_size), mask(_mask), interactionMask(_mask) {
	RegisterCollider();
}

idCollider::idCollider(floatVector2_t& _position, float w, float h, int _mask, int _interactionMask)
	: position(_position), size(w, h), mask(_mask), interactionMask(_mask) {
	RegisterCollider();
}

idCollider::~idCollider() {
	registeredColliders.erase(colliderID);
}

void idCollider::RegisterCollider() {
	colliderID = registeredIDs;
	registeredIDs++;

	registeredColliders[colliderID] = this;
}

bool idCollider::Collide(idCollider& a, idCollider& b) {
	return (
		a.position.x < b.position.x + b.size.x &&
		b.position.x < a.position.x + a.size.x &&
		a.position.y < b.position.y + b.size.y &&
		b.position.y < a.position.y + a.size.y
	);
}

bool idCollider::Collide(idCollider& a, idCollider& b, collision_t& col) {
	if (!Collide(a, b)) return false;

	float bottomCollide = b.position.y - (a.position.y + a.size.y);
	float topCollide = (b.position.y + b.size.y) - a.position.y;
	float rightCollide = b.position.x - (a.position.x + a.size.x);
	float leftCollide = (b.position.x + b.size.x) - a.position.x;

	floatVector2_t axis = (a.position + a.size / 2.0f) - (b.position + b.size / 2.0f);
	
	if (axis.y > 0.0f) {
		col.depth.y = bottomCollide;
	}
	else {
		col.depth.y = topCollide;
	}
	if (axis.x > 0.0f) {
		col.depth.x = rightCollide;
	}
	else {
		col.depth.x = leftCollide;
	}

	if (abs(col.depth.x) > abs(col.depth.y)) {
		col.normal.x = 0.0f;
		col.normal.y = signbit(col.depth.y) ? 1.0f : -1.0f;
	}
	else {
		col.normal.x = signbit(col.depth.x) ? 1.0f : -1.0f;
		col.normal.y = 0.0f;
	}

	return true;
}
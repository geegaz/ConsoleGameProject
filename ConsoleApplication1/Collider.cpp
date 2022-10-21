#include "Collider.h"


int idCollider::registeredIDs = 0;
map<int, idCollider*> idCollider::registeredColliders;

idCollider::idCollider(idLevelObject& _parent, floatVector2_t& _position, floatVector2_t _size, int _mask, int _interactionMask)
	: position(_position),size(_size), mask(_mask), interactionMask(_mask), parent(_parent) {
	RegisterCollider();
}

idCollider::idCollider(idLevelObject& _parent, floatVector2_t& _position, float w, float h, int _mask, int _interactionMask)
	: position(_position), size(w, h), mask(_mask), interactionMask(_mask), parent(_parent) {
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

	float bottomCollide = a.position.y - (b.position.y + b.size.y);
	float topCollide = (a.position.y + a.size.y) - b.position.y;
	float rightCollide = a.position.x - (b.position.x + b.size.x);
	float leftCollide = (a.position.x + a.size.x) - b.position.x;

	floatVector2_t axis = (a.position + a.size / 2.0f) - (b.position + b.size / 2.0f);
	
	if (axis.y > 0.0f) {
		axis.y = bottomCollide; // +
	}
	else {
		axis.y = topCollide; // -
	}
	if (axis.x > 0.0f) {
		axis.x = rightCollide; // +
	}
	else {
		axis.x = leftCollide; // -
	}

	if (abs(axis.x) > abs(axis.y)) {
		col.normal.x = 0.0f;
		col.normal.y = signbit(axis.y) ? 1.0f : -1.0f;
		col.depth = abs(axis.y);
	}
	else {
		col.normal.x = signbit(axis.x) ? 1.0f : -1.0f;
		col.normal.y = 0.0f;
		col.depth = abs(axis.x);
	}

	return true;
}
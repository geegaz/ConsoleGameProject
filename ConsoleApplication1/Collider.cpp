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


bool idCollider::Collide(idCollider& other) {
	return ( interactionMask & other.mask &&
		position.x < other.position.x + other.size.x &&
		other.position.x < position.x + size.x &&
		position.y < other.position.y + other.size.y &&
		other.position.y < position.y + size.y
	);
}

bool idCollider::Collide(idCollider& other, collision_t& col) {
	if (!Collide(other)) return false;

	float bottomCollide = position.y - (other.position.y + other.size.y);
	float topCollide = (position.y + size.y) - other.position.y;
	float rightCollide = position.x - (other.position.x + other.size.x);
	float leftCollide = (position.x + size.x) - other.position.x;

	floatVector2_t axis = (position + size / 2.0f) - (other.position + other.size / 2.0f);
	
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
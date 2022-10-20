#include "Collider.h"


int idCollider::registeredIDs = 0;
map<int, idCollider*> idCollider::registeredColliders;

idCollider::idCollider(floatVector2_t& _position, floatVector2_t _size) : position(_position), size(_size) {
	RegisterCollider();
}

idCollider::idCollider(floatVector2_t& _position, float w, float h) : position(_position), size(w, h) {
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
	
	floatVector2_t axis((a.position + a.size / 2.0f) - (b.position + b.size / 2.0f));
	
	if (abs(axis.y) < abs(axis.x)) {
		// Collision is on the Y axis
		col.normal.x = 0.0f;
		if (axis.y > 0.0f) {
			col.normal.y = 1.0f;
		}
		else {
			col.normal.y = -1.0f;
		}
	}
	else {
		// Collision is on the X axis
		col.normal.y = 0.0f;
		if (axis.x > 0.0f) {
			col.normal.x = 1.0f;
		}
		else {
			col.normal.x = -1.0f;
		}
	}

	return true;
}

bool idCollider::CollideBounds(idCollider& a, idCollider& b) {
	return (
		a.position.x + a.size.x > b.position.x + b.size.x ||
		b.position.x > a.position.x ||
		a.position.y + a.size.y > b.position.y + b.size.y ||
		b.position.y > a.position.y
		);
}
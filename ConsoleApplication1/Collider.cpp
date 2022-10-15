#include "Collider.h"


int idCollider::registeredIDs = 0;

idCollider::idCollider(floatVector2_t& _position, floatVector2_t _size) : position(_position), size(_size) {
	RegisterCollider();
}

idCollider::idCollider(floatVector2_t& _position, float w, float h) : position(_position), size(w, h) {
	RegisterCollider();
}

idCollider::~idCollider() {
	idCollider::registeredColliders.erase(colliderID);
}

void idCollider::RegisterCollider() {
	colliderID = idCollider::registeredIDs;
	idCollider::registeredIDs++;

	idCollider::registeredColliders[colliderID] = this;
}

bool idCollider::Collide(idCollider& a, idCollider& b) {
	return (
		a.position.x < b.position.x + b.size.x &&
		a.position.x + a.size.x > b.position.x &&
		a.position.y < b.position.y + b.size.y &&
		a.size.y + a.position.y > b.position.y
	);
}
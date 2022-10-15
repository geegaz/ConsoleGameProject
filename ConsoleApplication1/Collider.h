#pragma once

#include <map>
#include "Vector2D.h"

using namespace std;

class idCollider
{
private:
	static map<int, idCollider*> registeredColliders;
	static int registeredIDs;
	
	int colliderID;
	floatVector2_t& position;
	floatVector2_t size;

	idCollider();
	void RegisterCollider();
public:
	idCollider(floatVector2_t& _position, floatVector2_t _size);
	idCollider(floatVector2_t& _position, float w, float h);
	~idCollider();

	static bool Collide(idCollider& a, idCollider& b);
};


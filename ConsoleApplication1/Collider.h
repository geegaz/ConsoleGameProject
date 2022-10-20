#pragma once

#include <map>
#include "Vector2D.h"

using namespace std;

struct collision_t
{
	floatVector2_t normal;
	floatVector2_t depth;
};

class idCollider
{
private:
	idCollider();

protected:
	static map<int, idCollider*> registeredColliders;
	static int registeredIDs;

	void RegisterCollider();

public:
	int colliderID;
	bool trigger;
	floatVector2_t& position;
	floatVector2_t size;

	idCollider(floatVector2_t& _position, floatVector2_t _size);
	idCollider(floatVector2_t& _position, float w, float h);
	~idCollider();

	static bool Collide(idCollider& a, idCollider& b);
	static bool Collide(idCollider& a, idCollider& b, collision_t& col);
};


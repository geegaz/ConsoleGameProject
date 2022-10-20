#pragma once

#include <map>
#include "Vector2D.h"

using namespace std;

struct collision_t
{
	floatVector2_t normal;
	int otherMask;
	float depth;
};

class idCollider
{
private:
	idCollider();

protected:
	void RegisterCollider();

public:
	static map<int, idCollider*> registeredColliders;
	static int registeredIDs;

	const int mask;
	const int interactionMask;
	int colliderID;
	bool trigger;
	floatVector2_t& position;
	floatVector2_t size;

	idCollider(floatVector2_t& _position, floatVector2_t _size, int _mask = 1, int _interactionMask = 1);
	idCollider(floatVector2_t& _position, float w, float h, int _mask = 1 , int _interactionMask = 1);
	~idCollider();

	static bool Collide(idCollider& a, idCollider& b);
	static bool Collide(idCollider& a, idCollider& b, collision_t& col);
};


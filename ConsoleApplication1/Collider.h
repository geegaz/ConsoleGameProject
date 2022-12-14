#pragma once

#include <map>
#include "Vector2D.h"

class idLevelObject;

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
	idLevelObject& parent;
	bool trigger;
	floatVector2_t& position;
	floatVector2_t size;


	idCollider(idLevelObject& _parent, floatVector2_t& _position, floatVector2_t _size, int _mask = 1, int _interactionMask = 1);
	idCollider(idLevelObject& _parent, floatVector2_t& _position, float w, float h, int _mask = 1 , int _interactionMask = 1);
	~idCollider();

	bool Collide(idCollider& other);
	bool Collide(idCollider& other, collision_t& col);
};


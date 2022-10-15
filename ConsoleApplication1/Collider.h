#pragma once

#include <map>

using namespace std;

typedef struct rect_t {
	float x;
	float y;

	float w;
	float h;
};

class idCollider
{
private:
	static map<int, idCollider> registeredColliders;
	static int registeredIDs;
	
	int colliderID;

	void RegisterCollider();
public:
	rect_t colliderRect;

	idCollider();
	idCollider(rect_t& rect);
	idCollider(float x, float y, float w, float h);
	~idCollider();

	bool Collide(idCollider& a, idCollider& b);
};


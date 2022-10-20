#pragma once
#include "SpriteRenderer.h"
#include "Vector2D.h"
#include "Collider.h"
class idLevelObject
{
protected:
	idSpriteRenderer spriteRenderer;
	intVector2_t position;
	idCollider collider;
public:
	idLevelObject(int x, int y, idSprite sprite = idSprite(), floatVector2_t size = floatVector2_t(1.0f, 1.0f), int mask = 1, int interactionMask = 1);
	virtual void OnCollide(idCollider& other, collision_t collision) = 0;
	virtual ~idLevelObject();

};
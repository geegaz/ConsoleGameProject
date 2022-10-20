#include "LevelObject.h"

idLevelObject::idLevelObject(int x, int y, idAnimationRegister animationRegister,
	idSprite sprite, intVector2_t spriteOffset,
	floatVector2_t size,
	int mask, int interactionMask)
	: position(x,y), spriteRenderer(sprite, position, animationRegister, spriteOffset), collider(position, size, mask, interactionMask)
{
}

idLevelObject::~idLevelObject() {}
#include "Wall.h"
#include "GameConstants.h"
int idWall::MASK = BLOCK_MASK;
int idWall::INTERACTION_MASK = NONE_MASK;

idWall::idWall(int x, int y, int frame) : idLevelObject(x, y, idAnimationRegister::defaultRegister) {
	spriteRenderer.SetDefault(frame);
}

void idWall::OnCollide(idCollider& other, collision_t collision) {}

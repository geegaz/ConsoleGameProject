#include "Wall.h"
#include "GameConstants.h"
idSprite idWall::WALL_SPRITE(".\\resources\\sprites\\tileset_1.txt");
int idWall::MASK(WALL_MASK);
int idWall::INTERACTION_MASK(NONE_MASK);

idWall::idWall(int x, int y, int frame) : idLevelObject(x, y, idAnimationRegister::defaultRegister, WALL_SPRITE) {
	spriteRenderer.SetDefault(frame);
}

void idWall::OnCollide(idCollider& other, collision_t collision) {}

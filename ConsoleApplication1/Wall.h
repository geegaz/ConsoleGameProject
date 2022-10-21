#pragma once
#include "LevelObject.h"
class idWall :
    public idLevelObject
{
protected:
    static idSprite WALL_SPRITE;
    static int MASK;
    static int INTERACTION_MASK;
public:
    idWall(int x, int y, int frame = 0);
    virtual void OnCollide(idCollider& other, collision_t collision);
};


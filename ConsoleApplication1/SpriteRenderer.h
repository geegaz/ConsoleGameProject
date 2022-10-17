#pragma once
#include <vector>
#include "Vector2D.h"
#include "Sprite.h"
#include "Animation.h"
#include <map>
class idStaticSpriteRenderer {
private:
    idSprite& sprite;
public:
    idStaticSpriteRenderer(idSprite& _sprite);
    void Draw(idDisplay& display, intVector2_t offset = intVector2_t(0,0) ,int frame = 0);
};

class idSpriteRenderer {
protected:
    idSprite& sprite;
    map<string, positionAnimation_t*> positionAnimations;
    map<string, positionAnimation_t*> frameAnimations;
    animationState_t animationState;
    intVector2_t spriteOffset;
    intVector2_t& position;
    bool flipX;
public:
    void Draw(idDisplay& display, intVector2_t drawOffset);
    intVector2_t& GetPosition() { return position; }
};


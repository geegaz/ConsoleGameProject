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
    idAnimationState animationState;
    idAnimationRegister& animationRegister;
    intVector2_t spriteOffset;
    intVector2_t& position;
    bool flipX;
public:
    idSpriteRenderer(idSprite _sprite, intVector2_t& _position, intVector2_t _spriteOffset = intVector2_t(0, 0));
    bool SwitchPositionAnimation(string animationTitle);
    bool SwitchFrameAnimation(string animationTitle);
    void NextFrame();
    void NextPosition();
    void Draw(idDisplay& display, intVector2_t drawOffset);
    void SetFlipX(bool flip);
    intVector2_t& GetPosition() { return position; }
};
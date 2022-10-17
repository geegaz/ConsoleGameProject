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
    void Draw(idDisplay& display);

    /*
    void idSprite::Draw(idDisplay& display, int x, int y, int frame, bool flipX, bool flipY) {
        frame = min(framesX * framesY - 1, frame);

        int a = frame % framesX;
        int b = frame / framesX;
        int i = (sizeX * framesX) * (sizeY * b) + (sizeX * a);
        for (int iter_y = 0; iter_y < sizeY; iter_y++) {
            for (int iter_x = 0; iter_x < sizeX; iter_x++) {
                if (data[i] >= 0) {
                    display.DrawPixel(
                        x + iter_x,
                        y + iter_y,
                        data[i]
                    );
                }
                i++;
            }
            i += sizeX * (framesX - 1);
        }
    }
    */
};

class idSpriteRenderer {
protected:
    idSprite& sprite;
    map<string, positionAnimation_t*> positionAnimations;
    map<string, positionAnimation_t*> frameAnimations;
    animationState_t animationState;
    intVector2_t offset;
    intVector2_t& position;
    bool flipHorizontally;
public:
    void Draw(idDisplay& display, intVector2_t drawOffset);
    intVector2_t& GetPosition() { return position; }
};


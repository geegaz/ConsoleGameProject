#include "SpriteRenderer.h"
idStaticSpriteRenderer::idStaticSpriteRenderer(idSprite& _sprite):sprite(_sprite){}

void idStaticSpriteRenderer::Draw(idDisplay& display, intVector2_t offset, int frame) {
    frame = min(sprite.frames.x * sprite.frames.y - 1, frame);

    int a = frame % sprite.frames.x;
    int b = frame / sprite.frames.x;
    int i = (sprite.size.x * sprite.frames.x) * (sprite.size.y * b) + (sprite.size.x * a);
    for (int iter_y = 0; iter_y < sprite.size.y; iter_y++) {
        for (int iter_x = 0; iter_x < sprite.size.x; iter_x++) {
            if (sprite.data[i] >= 0) {
                display.DrawPixel(
                    offset.x + iter_x,
                    offset.y + iter_y,
                    sprite.data[i]
                );
            }
            i++;
        }
        i += sprite.size.x * (sprite.frames.x - 1);
    }
}

idSpriteRenderer::idSpriteRenderer(idSprite& _sprite, floatVector2_t& _position,
    idAnimationRegister& _animationRegister,
    intVector2_t _spriteOffset)
    : sprite(_sprite), spriteOffset(_spriteOffset), floatPosition(_position),
    animationRegister(_animationRegister), flipX(false) {}

void idSpriteRenderer::Draw(idDisplay& display, intVector2_t drawOffset) {
    intVector2_t total_draw_offset = drawOffset+spriteOffset;
    bool flipY = false;
    int frame;
    if (animationState.frameAnimation != nullptr) {
        frame = animationState.frameAnimation->frames[animationState.frameStep];
    }
    else
        frame = animationState.defaultFrame;
    if (animationState.positionAnimation != nullptr) {
        flipY = animationState.positionAnimation->flipY;
        total_draw_offset.y += animationState.positionAnimation->yPositions[animationState.yPositionStep];
    }

    int i;
    int frame_column = frame % sprite.frames.x;
    int frame_line = frame / sprite.frames.x;
    // creating 4 similar bits of code to optimize how many times conditions are checked
    if (flipX) {
        if (flipY) {
            i = (sprite.size.x * sprite.frames.x) * ((sprite.size.y * (frame_line + 1)) - 1) + (sprite.size.x * (frame_column + 1) - 1);
            for (int iter_y = 0; iter_y < sprite.size.y; iter_y++) {
                for (int iter_x = 0; iter_x < sprite.size.x; iter_x++) {
                    if (sprite.data[i] >= 0) {
                        display.DrawPixel(
                            total_draw_offset.x + iter_x,
                            total_draw_offset.y + iter_y,
                            sprite.data[i]
                        );
                    }
                    i--;
                }
                i -= sprite.size.x * (sprite.frames.x - 1);
            }
        }
        else {
            i = (sprite.size.x * sprite.frames.x) * (sprite.size.y * frame_line) + (sprite.size.x * (frame_column + 1) - 1);
            for (int iter_y = 0; iter_y < sprite.size.y; iter_y++) {
                for (int iter_x = 0; iter_x < sprite.size.x; iter_x++) {
                    if (sprite.data[i] >= 0) {
                        display.DrawPixel(
                            total_draw_offset.x + iter_x,
                            total_draw_offset.y + iter_y,
                            sprite.data[i]
                        );
                    }
                    i--;
                }
                i += sprite.size.x * (sprite.frames.x + 1);
            }
        }
    }
    else {
        if (flipY) {
            i = (sprite.size.x * sprite.frames.x) * ((sprite.size.y * (frame_line + 1)) - 1) + (sprite.size.x * frame_column);
            for (int iter_y = 0; iter_y < sprite.size.y; iter_y++) {
                for (int iter_x = 0; iter_x < sprite.size.x; iter_x++) {
                    if (sprite.data[i] >= 0) {
                        display.DrawPixel(
                            total_draw_offset.x + iter_x,
                            total_draw_offset.y + iter_y,
                            sprite.data[i]
                        );
                    }
                    i++;
                }
                i -= sprite.size.x * (sprite.frames.x + 1);
            }
        }
        else {
            // i = [go to line] + [go to column]
            i = (sprite.size.x * sprite.frames.x) * (sprite.size.y * frame_line) + (sprite.size.x * frame_column);
            for (int iter_y = 0; iter_y < sprite.size.y; iter_y++) {
                for (int iter_x = 0; iter_x < sprite.size.x; iter_x++) {
                    if (sprite.data[i] >= 0) {
                        display.DrawPixel(
                            total_draw_offset.x + iter_x,
                            total_draw_offset.y + iter_y,
                            sprite.data[i]
                        );
                    }
                    i++;
                }
                i += sprite.size.x * (sprite.frames.x - 1);
            }
        }
    }
}

void idSpriteRenderer::SetDefault(int frame) {
    animationState.defaultFrame = frame;
}

intVector2_t& idSpriteRenderer::GetSize() {
    return sprite.size;
}
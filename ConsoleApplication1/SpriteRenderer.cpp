#include "SpriteRenderer.h"
idStaticSpriteRenderer::idStaticSpriteRenderer(idSprite& _sprite):sprite(_sprite){}

void idStaticSpriteRenderer::Draw(idDisplay& display, intVector2_t offset, int frame) {
    frame = min(sprite.framesX * sprite.framesY - 1, frame);

    int a = frame % sprite.framesX;
    int b = frame / sprite.framesX;
    int i = (sprite.sizeX * sprite.framesX) * (sprite.sizeY * b) + (sprite.sizeX * a);
    for (int iter_y = 0; iter_y < sprite.sizeY; iter_y++) {
        for (int iter_x = 0; iter_x < sprite.sizeX; iter_x++) {
            if (sprite.data[i] >= 0) {
                display.DrawPixel(
                    offset.x + iter_x,
                    offset.y + iter_y,
                    sprite.data[i]
                );
            }
            i++;
        }
        i += sprite.sizeX * (sprite.framesX - 1);
    }
}


void idSpriteRenderer::Draw(idDisplay& display, intVector2_t drawOffset) {
    intVector2_t total_draw_offset = drawOffset+spriteOffset;
    bool flipY = false;
    int frame;
    if (animationState.frameAnimation != nullptr) {
        frame = animationState.frameAnimation->frames[animationState.frameStep];
    }
    else
        frame = 1;
    if (animationState.positionAnimation != nullptr) {
        flipY = animationState.positionAnimation->flipY;
        total_draw_offset.y += animationState.positionAnimation->yPositions[animationState.yPositionStep];
    }

    int i;
    int frame_column = frame % sprite.framesX;
    int frame_line = frame / sprite.framesX;
    // creating 4 similar bits of code to optimize how many times conditions are checked
    if (flipX) {
        if (flipY) {
            i = (sprite.sizeX * sprite.framesX) * ((sprite.sizeY * (frame_line + 1)) - 1) + (sprite.sizeX * (frame_column + 1) - 1);
            for (int iter_y = 0; iter_y < sprite.sizeY; iter_y++) {
                for (int iter_x = 0; iter_x < sprite.sizeX; iter_x++) {
                    if (sprite.data[i] >= 0) {
                        display.DrawPixel(
                            total_draw_offset.x + iter_x,
                            total_draw_offset.y + iter_y,
                            sprite.data[i]
                        );
                    }
                    i--;
                }
                i -= sprite.sizeX * (sprite.framesX - 1);
            }
        }
        else {
            i = (sprite.sizeX * sprite.framesX) * (sprite.sizeY * frame_line) + (sprite.sizeX * (frame_column + 1) - 1);
            for (int iter_y = 0; iter_y < sprite.sizeY; iter_y++) {
                for (int iter_x = 0; iter_x < sprite.sizeX; iter_x++) {
                    if (sprite.data[i] >= 0) {
                        display.DrawPixel(
                            total_draw_offset.x + iter_x,
                            total_draw_offset.y + iter_y,
                            sprite.data[i]
                        );
                    }
                    i--;
                }
                i += sprite.sizeX * (sprite.framesX + 1);
            }
        }
    }
    else {
        if (flipY) {
            i = (sprite.sizeX * sprite.framesX) * ((sprite.sizeY * (frame_line + 1)) - 1) + (sprite.sizeX * frame_column);
            for (int iter_y = 0; iter_y < sprite.sizeY; iter_y++) {
                for (int iter_x = 0; iter_x < sprite.sizeX; iter_x++) {
                    if (sprite.data[i] >= 0) {
                        display.DrawPixel(
                            total_draw_offset.x + iter_x,
                            total_draw_offset.y + iter_y,
                            sprite.data[i]
                        );
                    }
                    i++;
                }
                i -= sprite.sizeX * (sprite.framesX + 1);
            }
        }
        else {
            // i = [go to line] + [go to column]
            i = (sprite.sizeX * sprite.framesX) * (sprite.sizeY * frame_line) + (sprite.sizeX * frame_column);
            for (int iter_y = 0; iter_y < sprite.sizeY; iter_y++) {
                for (int iter_x = 0; iter_x < sprite.sizeX; iter_x++) {
                    if (sprite.data[i] >= 0) {
                        display.DrawPixel(
                            total_draw_offset.x + iter_x,
                            total_draw_offset.y + iter_y,
                            sprite.data[i]
                        );
                    }
                    i++;
                }
                i += sprite.sizeX * (sprite.framesX - 1);
            }
        }
    }
}
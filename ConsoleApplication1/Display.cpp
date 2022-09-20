#include "Display.h"

Display::Display(CHAR_INFO*& buffer, int width, int height){
    this->buffer = buffer;
    this->width = width;
    this->height = height;
}

void Display::Draw(int x, int y, int color) {
    int top_mask = 0x0F, bottom_mask = 0xF0;
    int x_coord, y_coord;
    x_coord = x;
    y_coord = y / 2;
    bool bottom = y % 2;
    if (!bottom) {
        buffer[y_coord*width + x_coord].Attributes &= bottom_mask;
        buffer[y_coord*width + x_coord].Attributes += color;
    }
    else {
        buffer[y_coord * width + x_coord].Attributes &= top_mask;
        buffer[y_coord * width + x_coord].Attributes += color<<4;
    }
}
#include "Display.h"
#include <iostream>
#include <string>

Display::Display(){
    hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
    dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
    dwBufferCoord = { 0, 0 };
    rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };
    buffer = new CHAR_INFO[SCREEN_HEIGHT * SCREEN_WIDTH];

    SetConsoleScreenBufferSize(hOutput, dwBufferSize);

    SetConsoleWindowInfo(hOutput, true, &rcRegion);

    ReadConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
    for (int j = UI_HEIGHT/2; j < SCREEN_HEIGHT; j++) {
        for (int i = 0; i < SCREEN_WIDTH; i++) {
            buffer[j * SCREEN_WIDTH + i].Char.UnicodeChar = 0x2580;
        }
    }
}

void Display::DrawPixel(int x, int y, int color) {
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT*2)
        return;
    int top_mask = 0x0F, bottom_mask = 0xF0;
    int x_coord, y_coord;
    x_coord = x;
    y_coord = y / 2;
    bool top = y % 2;
    int array_index = y_coord * SCREEN_WIDTH + x_coord;
    if (!top) {
        buffer[array_index].Attributes &= bottom_mask;
        buffer[array_index].Attributes += color;
    }
    else {
        buffer[array_index].Attributes &= top_mask;
        buffer[array_index].Attributes += color<<4;
    }  
}

void Display::Refresh() {
    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
}

void Display::Fill(int color) {
    for (int j = UI_HEIGHT/2; j < SCREEN_HEIGHT; j++) {
        for (int i = 0; i < SCREEN_WIDTH; i++) {
            buffer[j * SCREEN_WIDTH + i].Attributes = 0x11 * color;
            // buffer[j * SCREEN_WIDTH + i].Attributes = (((j + i) + (j % 2)) % 2) ? 0x00F0 : 0x000F;
        }
    }
}

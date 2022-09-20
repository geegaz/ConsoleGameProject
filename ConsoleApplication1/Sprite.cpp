#include "Sprite.h"
Sprite::Sprite() {
    sizeX = 1;
    sizeY = 1;

    int data_size = 1;
    this->data = new int[data_size];
    data[0] = 0;
}

Sprite::Sprite(ifstream& file, int size_x, int size_y) {
	this->sizeX = size_x;
	this->sizeY = size_y;

    int data_size = size_x * size_y;
    this->data = new int[data_size];

    for (size_t i = 0; i < data_size; i++)
    {
        data[i] = 4;
    }
}

Sprite::Sprite(int color, int size_x, int size_y) {
    this->sizeX = size_x;
    this->sizeY = size_y;

    int data_size = size_x * size_y;
    this->data = new int[data_size];

    for (size_t i = 0; i < data_size; i++)
    {
        data[i] = color;
    }
}

Sprite::~Sprite() {
    delete this->data;
}

int Sprite::Draw(Display& display, int x, int y) {
    
    for (size_t i = 0; i < this->sizeX * this->sizeY; i++)
    {
        if (data[i] >= 0) {
            display.DrawPixel(
                x + i % sizeX, 
                y + i / sizeY, 
                data[i]
            );
        }
    }
    return 0;
}
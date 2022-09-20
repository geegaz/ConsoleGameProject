#include "Sprite.h"

Sprite::Sprite() {
    sizeX = 1;
    sizeY = 1;

    int data_size = 1;
    this->data = new int[data_size];
    data[0] = 0;
}

Sprite::Sprite(ifstream& file) {
	/*this->sizeX = size_x;
	this->sizeY = size_y;*/

    string string_data;
    int int_data;

    int i = 0;
    int offset = 0;
    while (file) {
        file >> string_data;
        if (string_data == "---") {
            offset = i;
            this->data = new int[sizeX * sizeY];
        }
        else {
            int_data = stoi(string_data);
            switch (i)
            {
            case 0:
                sizeX = int_data;
                break;
            case 1:
                sizeY = int_data;
                break;
            default:
                data[i - offset] = int_data;
            }
            i++;
        }
    }

    cout << endl;
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

Sprite& Sprite::operator=(Sprite& other) {
    if (this != NULL && this != &other) {
        delete[] data;
        data = new int[other.sizeX*other.sizeY];
        sizeX = other.sizeX;
        sizeY = other.sizeY;
        for (int i = 0; i < other.sizeX * other.sizeY; i++)
            data[i] = other.data[i];
    }
    return *this;
}
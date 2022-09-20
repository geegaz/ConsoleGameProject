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

    string size_x_string;
    string size_y_string;
    getline(file, size_x_string);
    getline(file, size_y_string);

    sizeX = stoi(size_x_string);
    sizeY = stoi(size_y_string);
    int data_size = sizeX * sizeY;
    this->data = new int[data_size];

    int i = 0;
    while (file && i < data_size) {
        char c = file.get();
        if (c >= 'A' && c <= 'F') {
            data[i] = c - 'A' + 10;
        }
        else {
            if (c >= '0' && c <= '9') {
                data[i] = c - '0';
            }
            else {
                if (c == ' ') {
                    data[i] = -1;
                }
            }
        }
        i++;
    }

    cout << sizeX << " " << sizeY << endl;
    for (int i = 0; i < data_size; i++)
    {
        cout << data[i];
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
#include "Sprite.h"
#include "Vector2D.h"
idSprite::idSprite() {
    sizeX = 1;
    sizeY = 1;

    framesX = 1;
    framesY = 1;

    int data_size = 1;
    data = new int[data_size];
    data[0] = 0;
}

idSprite::idSprite(string filename) {
    sizeX = 1;
    sizeY = 1;

    framesX = 1;
    framesY = 1;
    
    data = nullptr;
    ifstream file(filename);

    string string_data;
    int int_data;

    int i = 0;
    //--- Get header
    while (file >> string_data) {
        if (string_data == "---") {
            i = 0;
            data = new int[sizeX * framesX * sizeY * framesY];
            break;
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
            case 2:
                framesX = int_data;
                break;
            case 3:
                framesY = int_data;
            default:
                break;
            }
            i++;
        }
    }
    //--- Get data
    while (file >> string_data) {
        int_data = stoi(string_data);

        data[i] = int_data;
        i++;
    }
    file.close();
    if (data == nullptr) {
        int data_size = 1;
        data = new int[data_size];
        data[0] = 0;
    }
}

idSprite::idSprite(int color, int size_x, int size_y) {
    sizeX = size_x;
    sizeY = size_y;

    framesX = 1;
    framesY = 1;

    int data_size = size_x * size_y;
    data = new int[data_size];

    for (size_t i = 0; i < data_size; i++)
    {
        data[i] = color;
    }
}

idSprite::~idSprite() {
    delete[] this->data;
}

void idSprite::Draw(idDisplay& display, int x, int y, int frame) {
    idSprite& sprite = *this;
    intVector2_t total_draw_offset = intVector2_t(x, y);
    frame = min(framesX * framesY - 1, frame);
    bool flipHorizontally = true, flipVertically = true;
    int frame_column, frame_line, i;
    frame_column = frame % sprite.framesX;
    frame_line = frame / sprite.framesX;
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

//idSprite& idSprite::operator=(idSprite& other) {
//    if (this != NULL && this != &other) {
//        delete[] data;
//        data = new int[other.sizeX*other.sizeY];
//        sizeX = other.sizeX;
//        sizeY = other.sizeY;
//        for (int i = 0; i < other.sizeX * other.sizeY; i++)
//            data[i] = other.data[i];
//    }
//    return *this;
//}
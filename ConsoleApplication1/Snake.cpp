#include "Snake.h"

Snake::Snake(Sprite& snake, Sprite& apple){
	size = BASE_SIZE;
	snakeSprite = snake;
	appleSprite = apple;
	direction = RIGHT;
	map = new int[MAP_HEIGHT * MAP_WIDTH];
	headX = 0;
	headY = 0;
	
	for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH; i++)
		map[i] = 0;
	
}

Snake::~Snake() {
	delete[] map;
}
void Snake::Start() {
	int center_x = MAP_WIDTH / 2, center_y = MAP_HEIGHT / 2;
	map[TO_INDEX(center_x, center_y)] = size;
	headX = center_x;
	headY = center_y;
	cout << "(" << center_x << "," << center_y << ")";
	GenerateFood();
}
void Snake::GenerateFood() {
	bool drawn = false;
	while (!drawn) {
		rand(); rand(); 
		int ypos = rand() % MAP_HEIGHT, xpos = rand() % MAP_WIDTH;
		if (map[TO_INDEX(xpos, ypos)] == 0) {
			map[TO_INDEX(xpos, ypos)] = APPLE_TILE;
			drawn = true;
			cout << "(" << xpos << "," << ypos << ")"<<endl;
		}
	}
}

void Snake::DrawGame(Display& display) {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			int tile = map[TO_INDEX(j, i)];
			if (tile>0) {
				snakeSprite.Draw(display, j * SPRITE_SIZE, i * SPRITE_SIZE + UI_HEIGHT);
			}
			else
				if (tile == APPLE_TILE) {
					appleSprite.Draw(display, j * SPRITE_SIZE, i * SPRITE_SIZE + UI_HEIGHT);
				}
		}
	}
}

void Snake::Update() {
	switch (direction) {
	case RIGHT:
		headX += 1;
		break;
	default:
		break;
	}
	map[TO_INDEX(headX, headY)] = size + 1;
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (map[TO_INDEX(j, i)] > 0)
				map[TO_INDEX(j, i)]--;
		}
	}
}
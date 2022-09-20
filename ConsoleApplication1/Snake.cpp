#include "Snake.h"

Snake::Snake(Sprite snake, Sprite apple){
	size = BASE_SIZE;
	snakeSprite = snake;
	appleSprite = apple;
	map = new int[MAP_HEIGHT * MAP_LENGTH];
}

Snake::~Snake() {
	delete[] map;
}
void Snake::Start() {
	int ypos = rand() % MAP_HEIGHT, xpos = rand() % MAP_LENGTH;

	GenerateFood();
}
void Snake::GenerateFood() {
	
}

void Snake::DrawGame(Display display) {

}

void Snake::Update() {

}
#include "Snake.h"

idSnake::idSnake(idSprite& snake, idSprite& apple):size(BASE_SIZE), snakeSprite(snake), appleSprite(apple), headX(0), headY(0), gameOver(true), logic_delay(0.5f), logic_timer(0.0f), state(gameState_t::MENU){
	map = new int[MAP_HEIGHT * MAP_WIDTH];
}

idSnake::~idSnake() {
	delete[] map;
}

void idSnake::Start() {
	gameOver = false;
	size = BASE_SIZE;
	for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH; i++)
		map[i] = 0;
	int center_x = MAP_WIDTH / 2, center_y = MAP_HEIGHT / 2;
	map[TO_INDEX(center_x, center_y)] = size;
	headX = center_x;
	headY = center_y;
	logic_delay = 0.5f;
	logic_timer = 0.0f;
	GenerateFood();
	state = gameState_t::IN_GAME;
}
void idSnake::GenerateFood() {
	bool drawn = false;
	while (!drawn) {
		int ypos = rand() % MAP_HEIGHT, xpos = rand() % MAP_WIDTH;
		if (map[TO_INDEX(xpos, ypos)] == 0) {
			map[TO_INDEX(xpos, ypos)] = APPLE_TILE;
			drawn = true;
		}
	}
}

void idSnake::DrawGame(idDisplay& display) {
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

void idSnake::Update(control_t direction) {
	logic_timer -= logic_delay;
	if (!gameOver) {
		switch (direction) {
		case control_t::RIGHT:
			headX += 1;
			break;
		case control_t::LEFT:
			headX -= 1;
			break;
		case control_t::UP:
			headY -= 1;
			break;
		case control_t::DOWN:
			headY += 1;
			break;
		default:
			return;
		}
		if (headX < 0 || headX >= MAP_WIDTH || headY < 0 || headY >= MAP_HEIGHT) {
			state = gameState_t::MENU;
			gameOver = true;
			return;
		}
		int destination_index = TO_INDEX(headX, headY);
		if (map[destination_index] != APPLE_TILE) {
			for (int i = 0; i < MAP_HEIGHT; i++) {
				for (int j = 0; j < MAP_WIDTH; j++) {
					if (map[TO_INDEX(j, i)] > 0)
						map[TO_INDEX(j, i)]--;
				}
			}
			if (map[destination_index] >= 1) {
				gameOver = true;
				return;
			}
			map[destination_index] = size;
		}
		else {
			size++;
			map[destination_index] = size;
			if (logic_delay > 0.05f)
				logic_delay*=0.95f;
			GenerateFood();
			PlaySound(L".\\resources\\sounds\\sfx8.wav", NULL, SND_ASYNC);
		}
	}
}

bool idSnake::CanMove() {
	return logic_timer >= logic_delay;
}
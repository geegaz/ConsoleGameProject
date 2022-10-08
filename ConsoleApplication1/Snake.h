#pragma once
#include "Display.h"
#include "Sprite.h"
#include "GameConstants.h"
#define MAP_HEIGHT ((SCREEN_HEIGHT*2-UI_HEIGHT)/4)
#define MAP_WIDTH (SCREEN_WIDTH/4)

#define BASE_SIZE 3
#define TO_INDEX(X,Y) (X+Y*MAP_WIDTH)
#define SPRITE_SIZE 4
#define APPLE_TILE -1

class idSnake
{
private:
	float logic_delay; // delay in seconds between snake moves
	float logic_timer; // elapsed time between a snake's move
	int* map;
	int size;
	int headX, headY;
	bool gameOver;
	gameState_t state;
public:
	idSprite snakeSprite, appleSprite;
	idSnake(idSprite& snake, idSprite& apple);
	~idSnake();
	void Start();
	void GenerateFood();
	void DrawGame(idDisplay& display);
	void Update(control_t);
	int Score() { return size - BASE_SIZE; }
	bool IsGameOver() { return gameOver; }
	bool CanMove();
	void Forward(float time) { logic_timer += time; }
	gameState_t GetState() { return state; }
};


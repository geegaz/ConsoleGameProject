#pragma once
#include "Display.h"
#include "Sprite.h"
#define MAP_HEIGHT ((SCREEN_HEIGHT*2-UI_HEIGHT)/4)
#define MAP_LENGTH (SCREEN_WIDTH/4)
#define BASE_SIZE 3
class Snake
{
private:
	Sprite snakeSprite, appleSprite;
	int* map;
	int size;
public:
	Snake(Sprite snake, Sprite apple);
	~Snake();
	void Start();
	void GenerateFood();
	void InitSnake();
	void DrawGame(Display display);
	void Update();
	int Score() { return size - BASE_SIZE; }
};


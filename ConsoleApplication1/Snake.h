#pragma once
#include "Display.h"
#include "Sprite.h"
#include "NYTimer.h"
#include "InputManager.h"
#include "ControlsManager.h"
#include "NumberDisplay.h"
#include "GameConstants.h"
#include "SoundManager.h"
#include "ParticlesManager.h"
#define MAP_HEIGHT ((SCREEN_HEIGHT*2-UI_HEIGHT)/4)
#define MAP_WIDTH (SCREEN_WIDTH/4)

#define BASE_SIZE 3
#define TO_INDEX(X,Y) (X+Y*MAP_WIDTH)
#define SPRITE_SIZE 4
#define APPLE_TILE -1

class idSnake
{
private:
	float logicDelay; // delay in seconds between snake moves
	float logicTimer; // elapsed time between a snake's move
	int* map;
	int size;
	intVector2_t headPosition;
	control_t direction, nextDirection;
	bool gameOver;
	idSprite snakeSprite, appleSprite,
		gameBackground, titleScreen,
		pressSpacePrompt,
		gameOverBackground, gameOverText, deadSprite;
	idDisplay display;
	NYTimer timer;
	idInputManager inputManager;
	idControlsManager controlsManager;
	idSoundManager soundManager;
	idNumberDisplay scoreDisplay, gameOverScoreDisplay;
	idParticlesManager particlesManager;
	const float frameDelay;
	void GenerateFood();
	void CreateDeathEffect();
	void DisplayStartPrompt(bool reset = false);
	void DrawGame(idDisplay& display);
	void DrawGameOver(idDisplay& display);
	void LoopTitle();
	void LoopGame();
	void LoopGameOver();
	void LoopDeath();
	void Update();
	void CheckInputs();
	void ChangeDirection(control_t newDirection);
	int Score() { return size - BASE_SIZE; }
	intVector2_t NextMove();
	void Initialize();
public:
	idSnake();
	~idSnake();
	void Start();
};


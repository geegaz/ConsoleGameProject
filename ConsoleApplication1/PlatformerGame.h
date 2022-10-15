#pragma once
#include "Sprite.h"
#include "NYTimer.h"
#include "Display.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputManager.h"
#include "ScoreDisplay.h"
#include "LevelLoader.h"
#include "GameplayDisplay.h"
#include <vector>
class idPlatformerGame
{
private:
	idSprite gameBackground;
	idDisplay display;
	idScoreDisplay scoreDisplay;
	idGameplayDisplay gameplayDisplay;
	NYTimer frameTimer;
	idInputManager inputManager;
	int** structure;
	idSprite structureSprite;
	int levelx, levely;
	int livesCount;
	int level;
	int score;
public:
	idPlatformerGame();
	void Start();
	void IterateGameLoop();
	~idPlatformerGame();
};


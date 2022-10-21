#pragma once
#include "Sprite.h"
#include "NYTimer.h"
#include "Display.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputManager.h"
#include "ScoreDisplay.h"
#include "LevelLoader.h"
#include "LevelDisplayer.h"
#include <vector>
#include "Mario.h"
extern idMarioState marioState;
class idPlatformerGame
{
private:
	idSprite gameBackground;
	idDisplay display;
	idScoreDisplay scoreDisplay;
	idLevelDisplayer levelDisplayer;
	NYTimer frameTimer;
	idInputManager inputManager;
	idMario mario;
	int levelx, levely;
	int livesCount;
	int level;
	int score;
	vector<idLevelObject*> levelStructure;
	void UpdatePhysics();
public:
	idPlatformerGame();
	void Start();
	void IterateGameLoop();
	void LoadLevel();
	void UpdateView();
	void UpdateLogic();
	~idPlatformerGame();
};


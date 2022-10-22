#pragma once
#include "Sprite.h"
#include "NYTimer.h"
#include "Display.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputManager.h"
#include "NumberDisplay.h"
#include "LevelLoader.h"
#include "LevelDisplayer.h"
#include <vector>
#include "Mario.h"
extern idMarioState marioState;
class idPlatformerGame
{
private:
	static idSprite OVERWORLD_BACKGROUND;
	idStaticSpriteRenderer gameBackground;
	idDisplay display;
	idNumberDisplay scoreDisplay;
	idStaticSpriteRenderer livesIcon;
	idSprite livesIconSprite;
	idNumberDisplay livesCountDisplay;
	idNumberDisplay coinsCountDisplay;
	idLevelDisplayer levelDisplayer;
	NYTimer frameTimer;
	idInputManager inputManager;
	idMario mario;
	int levelx, levely;
	int livesCount;
	int level;
	int score;
	bool started;
	vector<idLevelObject*> levelStructure;
	void ShowLifeScreen();
	void Update();
	void LoadLevel();
	void UpdateView();
	void UpdatePhysics();
	void UpdateLogic();

public:
	idPlatformerGame();
	void Start();
	~idPlatformerGame();
};


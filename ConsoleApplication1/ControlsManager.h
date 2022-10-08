#pragma once
#include "Snake.h"
#include "InputManager.h"
#include <vector>
#include <map>



class idControlsManager
{
private:
	idSnake& controller;
	map<gameState_t, map<int, control_t>> keyMappings, buttonMappings;
	gameState_t state;
public:
	idControlsManager(idSnake&);
	void MapKeys();
	void ReadInputStates(const map<int, keyState_t>&, const map<int, keyState_t>&) const;
	void SetState(gameState_t newState) { state = newState; }
};


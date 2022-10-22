#pragma once
#include "InputManager.h"
#include "GameConstants.h"
#include <vector>
#include <map>



class idControlsManager
{
private:
	map<gameState_t, map<int, control_t>> keyMappings, buttonMappings;
	gameState_t state;
	idInputManager& inputManager;
public:
	idControlsManager(idInputManager&);
	void MapKeys();
	void SetState(gameState_t newState) { state = newState; }
	keyState_t GetControlState(control_t);
};


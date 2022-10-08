#include "ControlsManager.h"
#include "GameConstants.h"


idControlsManager::idControlsManager(idSnake& game):controller(game), state(gameState_t::MENU){
    MapKeys();
}

void idControlsManager::MapKeys() {
    keyMappings[gameState_t::MENU] = KEYBOARD_MAPPING;
    keyMappings[gameState_t::IN_GAME] = KEYBOARD_MAPPING;
	buttonMappings[gameState_t::MENU] = XINPUT_MAPPING;
	buttonMappings[gameState_t::IN_GAME] = XINPUT_MAPPING;
}

void idControlsManager::ReadInputStates(const map<int, keyState_t>& keyboardInputs, const map<int, keyState_t>& xInputs) const {
	auto i = keyboardInputs.begin();
	auto end = keyboardInputs.end();
	auto i_x = xInputs.begin();
	auto end_x = xInputs.end();
	int key;
	gameState_t state = controller.GetState();
	switch (state)
	{
	case gameState_t::MENU:
		while (i != end) {
			key = (*i).first;
			if (keyMappings.at(state).at(key) == control_t::START && (*i).second.justPressed) {
				controller.Start();
				return;
			}
			i++;
		}
		while (i_x != end_x) {
			key = (*i_x).first;
			if (buttonMappings.at(state).at(key) == control_t::START && (*i_x).second.justPressed) {
				controller.Start();
				return;
			}
			i_x++;
		}
		break;

	case gameState_t::IN_GAME:
		while (i != end) {
			key = (*i).first;
			if (keyMappings.at(state).at(key) != control_t::START && (*i).second.pressed) {
				controller.Update(keyMappings.at(state).at(key));
				return;
			}
			i++;
		}
		while (i_x != end_x) {
			key = (*i_x).first;
			if (buttonMappings.at(state).at(key) != control_t::START && (*i_x).second.pressed) {
				controller.Update(buttonMappings.at(state).at(key));
				return;
			}
			i_x++;
		}
		controller.Update(control_t::START);
		break;
	default:
		break;
	}
}
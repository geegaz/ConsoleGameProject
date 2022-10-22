#include "ControlsManager.h"
#include "GameConstants.h"


idControlsManager::idControlsManager(idInputManager& inputManagerRef): inputManager(inputManagerRef), state(gameState_t::MENU){
    MapKeys();
}

void idControlsManager::MapKeys() {
    keyMappings[gameState_t::MENU] = KEYBOARD_MENU_MAPPING;
    keyMappings[gameState_t::IN_GAME] = KEYBOARD_MAPPING;
	buttonMappings[gameState_t::MENU] = XINPUT_MENU_MAPPING;
	buttonMappings[gameState_t::IN_GAME] = XINPUT_MAPPING;
}

keyState_t idControlsManager::GetControlState(control_t control) {
	keyState_t control_state = keyState_t();
	auto i = keyMappings[state].begin();
	auto end = keyMappings[state].end();
	auto i_x = buttonMappings[state].begin();
	auto end_x = buttonMappings[state].end();

	while (i != end) {
		if((*i).second == control){
			control_state |= inputManager.GetKeyStates()[(*i).first];
		}
		i++;
	}
	while (i_x != end_x) {
		if ((*i_x).second == control) {
			control_state |= inputManager.GetKeyStates()[(*i_x).first];
		}
		i_x++;
	}
	return control_state;

}
#include "InputManager.h"
#include <iostream>
#include <windows.h>
#include "GameConstants.h"

#define DOWN_MASK 0x8000
using namespace std;
idInputManager::idInputManager() {
	auto i = KEYBOARD_MAPPING.begin();
	auto end = KEYBOARD_MAPPING.end();
	int key;
	while (i != end) {
		key = (*i).first;
		keys[key] = keyState_t();
		i++;
	}

	i = XINPUT_MAPPING.begin();
	end = XINPUT_MAPPING.end();
	int button;
	while (i != end) {
		button = (*i).first;
		buttons[button] = keyState_t();
		i++;
	}
	RefreshXinputInfo();
}

/*
void idInputManager::AddKey(int keyCode) {
	keys[keyCode] = keyState_t();
}

void idInputManager::RemoveKey(int keyCode) {
	keys.erase(keyCode);
}
*/

void idInputManager::CheckKeyInputs() {
	auto i = keys.begin();
	auto end = keys.end();
	int key;
	while (i != end) {
		key = (*i).first;
		if (GetKeyState(key) & DOWN_MASK) {
			if (!keyInputsQueue.count(key)) { // check if input is not already added to the map
				keyInputsQueue[key] = keyInstantState_t();
				keyInputsQueue[key].press = true;
			}
		}
		else {
			if (keyInputsQueue.count(key)) { // check if input is already added to the map
				if ((*i).second.pressed)
					keyInputsQueue[key].press = false;
				keyInputsQueue[key].release = true;
			}
		}
		i++;
	}
	RefreshXinputInfo();
	if (xinputDetected) {
		i = buttons.begin();
		end = buttons.end();
		int button;
		while (i != end) {
			button = (*i).first;
			if (button & xinputInfo) { // check if controller button is pressed
				if (!buttonInputsQueue.count(button)) { // check if input is not already added to the map
					buttonInputsQueue[button] = keyInstantState_t();
					buttonInputsQueue[button].press = true;
				}
			}
			else {
				if (buttonInputsQueue.count(button)) { // check if input is already added to the map
					if ((*i).second.pressed)
						buttonInputsQueue[button].press = false;
					buttonInputsQueue[button].release = true;
				}
			}
			i++;
		}
	}
}

void idInputManager::UpdateStates() {
	auto i = keys.begin();
	auto end = keys.end();
	int key;
	while (i != end) {
		key = (*i).first;
		auto& keyState = (*i).second;
		if (keyInputsQueue.count(key)) { // check if key was pressed/held/released during the frame
			keyState.justReleased = keyInputsQueue[key].release; // true if key is pressed and released on the same frame
			keyState.justPressed = !(keyState.pressed); // key is justPressed if it's down and wasn't previously pressed
			keyState.pressed = keyInputsQueue[key].press; // false if key was preivously pressed and is now released
		}
		else {
			keyState.justReleased = keyState.pressed; // key is justReleased if it's not down and was previously pressed

			keyState.justPressed = false;
			keyState.pressed = false;
		}
		i++;
	}
	keyInputsQueue.clear();

	if (xinputDetected) {
		i = buttons.begin();
		end = buttons.end();
		int button;
		while (i != end) {
			button = (*i).first;
			auto& buttonState = (*i).second;
			if (buttonInputsQueue.count(button)) { // check if button was pressed/held/released during the frame
				buttonState.justReleased = buttonInputsQueue[button].release; // true if button is pressed and released on the same frame
				buttonState.justPressed = !(buttonState.pressed); // button is justPressed if it's down and wasn't previously pressed
				buttonState.pressed = buttonInputsQueue[button].press; // false if button was preivously pressed and is now released
			}
			else {
				buttonState.justReleased = buttonState.pressed; // button is justReleased if it's not down and was previously pressed

				buttonState.justPressed = false;
				buttonState.pressed = false;
			}
			i++;
		}
		buttonInputsQueue.clear();
	}
}

void idInputManager::RefreshXinputInfo() {
	// based on https://learn.microsoft.com/fr-fr/windows/win32/xinput/getting-started-with-xinput
	DWORD dwResult;
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE)); // clear memory state
	dwResult = XInputGetState(0, &state); // get the state of the controller from XInput
	xinputDetected = dwResult == ERROR_SUCCESS; // true if controller is detected
	if (xinputDetected) {
		xinputInfo = state.Gamepad.wButtons;
	}
	else {
		xinputInfo = 0;
	}
}
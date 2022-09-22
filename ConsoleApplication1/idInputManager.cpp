#include "idInputManager.h"
#include <iostream>
#include <windows.h>
#define DOWN_MASK 0x8000
using namespace std;
void idInputManager::AddKey(int keyCode) {
	keys[keyCode] = keyState_t();
}

void idInputManager::RemoveKey(int keyCode) {
	if (lastKey == keyCode)
		lastKey = -1;
	keys.erase(keyCode);
}

void idInputManager::UpdateKeys() {
	auto i = keys.begin();
	auto end = keys.end();
	while (i != end) {
		if ((GetKeyState((*i).first) & DOWN_MASK)) {
			//(*i).second.pressed = true;
			//for now, only the latest input is registered
			lastKey = (*i).first;
		}
		i++;
	}
}


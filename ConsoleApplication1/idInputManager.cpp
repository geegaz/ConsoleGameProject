#include "idInputManager.h"
#include <iostream>
#include <windows.h>
#define DOWN_MASK 0x8000
using namespace std;
void idInputManager::AddKey(int keyCode) {
	keys[keyCode] = keyState_t();
}

void idInputManager::UpdateKeys() {
	auto i = keys.begin();
	auto end = keys.end();
	while (i != end) {
		if ((GetKeyState((*i).first) & DOWN_MASK)) {
			//cout << (*i).first << " " << hex << "PRESSED" << endl;
			(*i).second.pressed = true;
			lastKey = (*i).first;
		}
		i++;
	}
}


#pragma once
#include <map>
using namespace std;
struct keyState_t {
	bool justPressed;
	bool pressed;
	bool justReleased;

	keyState_t operator|=(keyState_t&);
};

struct keyInstantState_t {
	bool press;
	bool release;
};

class idInputManager
{
private:
	map<int, keyState_t> keys;
	map<int, keyInstantState_t> keyInputsQueue;
	// Controller compatibility
	map<int, keyState_t> buttons;
	map<int, keyInstantState_t> buttonInputsQueue;
	bool xinputDetected;
	unsigned short xinputInfo;
public:
	idInputManager();
	void CheckKeyInputs();
	void UpdateStates();
	map<int, keyState_t> GetKeyStates() { return keys; }
	map<int, keyState_t> GetButtonStates() { return buttons; }
	void RefreshXinputInfo();
};
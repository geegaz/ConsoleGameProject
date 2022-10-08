#pragma once
#include <map>
using namespace std;
typedef struct {
	bool justPressed;
	bool pressed;
	bool justReleased;
}keyState_t;

typedef struct {
	bool press;
	bool release;
}keyInstantState_t;

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
	/*
	void AddKey(int keyCode);
	void RemoveKey(int keyCode);
	*/
	void CheckKeyInputs();
	void UpdateStates();
	map<int, keyState_t> GetKeyStates() { return keys; }
	map<int, keyState_t> GetButtonStates() { return buttons; }
	void RefreshXinputInfo();
};
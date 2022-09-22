#pragma once
#include <map>
using namespace std;
typedef struct {
	bool justPressed;
	bool pressed;
	bool justReleased;
}keyState_t;

class idInputManager
{
private:
	map<int, keyState_t> keys;
public:
	int lastKey;
	idInputManager():lastKey(-1){}
	void AddKey(int keyCode);
	void RemoveKey(int keyCode);
	void UpdateKeys();
};
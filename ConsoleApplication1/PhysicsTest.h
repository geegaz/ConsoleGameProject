#pragma once
#include <windows.h>
#include <vector>
#include "Collider.h"
#include "Display.h"
#include "ScoreDisplay.h"
#include "ControlsManager.h"

using namespace std;

class idPhysicsTest
{
private:
	idDisplay& display;
	idControlsManager& controls;
public:

	idPhysicsTest(idDisplay& displ, idControlsManager& in);
	void Main();
};


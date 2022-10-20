#pragma once
#include "SpriteRenderer.h"
class idMarioState
{
private:
	bool big;
	bool fire;
public:
	idMarioState();
	bool IsBig();
	bool IsFire();
	bool PowerUp();
	bool PowerDown();
	void Reset();
};

enum class marioAnimations_t {
	IDLE,
	WALK,
	JUMP,
	DEATH,
	TURN
};

class idMario {
private:
	static std::map<marioAnimations_t, std::string> smallAnimationTitles;
public:
	idMario();
};
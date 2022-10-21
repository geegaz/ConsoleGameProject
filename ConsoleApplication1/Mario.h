#pragma once
#include "LevelObject.h"
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

class idMario: public idLevelObject {
private:
	static std::map<marioAnimations_t, std::string> smallAnimationTitles;
	static int MASK;
	static int INTERACTION_MASK;
	static idSprite MARIO_SPRITES;
public:
	idMario();
	virtual void OnCollide(idCollider& other, collision_t collision);
};
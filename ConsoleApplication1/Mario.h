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
	static idSprite MARIO_SPRITES;
	static int MASK;
	static int INTERACTION_MASK;

	floatVector2_t velocity;
	float gravity;
public:
	float acceleration;
	float deceleration;
	float gravity_max;
	float gravity_min;
	float jump_height;
	float air_control;

	idMario();
	void Update();
	void Move(floatVector2_t vel, float delta);
	virtual void OnCollide(idCollider& other, collision_t collision);
};
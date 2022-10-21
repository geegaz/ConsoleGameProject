#include "Mario.h"
#include "GameConstants.h"
int idMario::MASK(PLAYER_MASK);
int idMario::INTERACTION_MASK(BLOCK_MASK+WALL_MASK+ENEMY_MASK+POWERUP_MASK);
idSprite idMario::MARIO_SPRITES(SPRITES_PATH + "mariospritesheet.txt");
idMarioState::idMarioState() : big(false), fire(false) {}

bool idMarioState::IsBig() {
	return big;
}

bool idMarioState::IsFire() {
	return fire;
}

bool idMarioState::PowerUp() {
	if (!big) {
		big = true;
		return true;
	}
	if (!fire) {
		fire = true;
		return true;
	}
	return false;
}

bool idMarioState::PowerDown() {
	if (fire) {
		fire = false;
		return true;
	}
	if (big) {
		big = false;
		return true;
	}
	return false;
}

void idMarioState::Reset() {
	big = false;
	fire = false;
}

idMario::idMario():idLevelObject(20,20,idAnimationRegister::defaultRegister,MARIO_SPRITES){}

void idMario::OnCollide(idCollider& other, collision_t collision) {

}
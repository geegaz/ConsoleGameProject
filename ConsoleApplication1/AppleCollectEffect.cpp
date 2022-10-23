#include "GameConstants.h"
#include "AppleCollectEffect.h"

idSprite idAppleCollectEffect::APPLE_COLLECT_FRAMES(SPRITES_PATH+"apple_pop.txt");
idAnimationRegister idAppleCollectEffect::APPLE_COLLECT_REGISTER;

idAppleCollectEffect::idAppleCollectEffect(int x, int y):idParticle(x,y, idAppleCollectEffect::APPLE_COLLECT_FRAMES, 20, APPLE_COLLECT_REGISTER, intVector2_t(-2, -1)), timer(0){
	APPLE_COLLECT_REGISTER.LoadFrameAnimations(ANIMATIONS_PATH + "apple_collect.txt");
	APPLE_COLLECT_REGISTER.LoadPositionAnimations(ANIMATIONS_PATH + "apple_collect.txt");
	GetRenderer().SwitchFrameAnimation("apple.collect");
	GetRenderer().SwitchPositionAnimation("apple.collect");

}

void idAppleCollectEffect::Update() {
	if (timer % 4 == 0) {
		idParticle::Update();
	}
	timer++;
}

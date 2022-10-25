#include "GameConstants.h"
#include "AppleCollectEffect.h"

idSprite idAppleCollectEffect::APPLE_COLLECT_FRAMES(SPRITES_PATH+"apple_pop.txt");

idAppleCollectEffect::idAppleCollectEffect(int x, int y):idParticle(x,y, idAppleCollectEffect::APPLE_COLLECT_FRAMES, 20, "apple.collect", "apple.collect", intVector2_t(-2, -1)), timer(0) {}

void idAppleCollectEffect::Update() {
	if (timer % 4 == 0) {
		idParticle::Update();
	}
	timer++;
}

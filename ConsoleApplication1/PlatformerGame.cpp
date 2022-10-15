#include "PlatformerGame.h"

idPlatformerGame::idPlatformerGame():
gameBackground("resources\\sprites\\gameBackground.txt"),
structureSprite("resources\\sprites\\tileset_1.txt"),
gameplayDisplay(display),
livesCount(0), level(0),levelx(32),levely(10), score(69){
	structure = idLevelLoader::LoadCsv("resources\\levels\\test.txt", 32, 10);
}

void idPlatformerGame::Start() {
	float frame_delay = 1.0f / 120.0f; // delay between frames
	float delta_time = 0.0f; // elapsed time between a frame
	frameTimer.getElapsedSeconds(true);
	while (true) {
		delta_time = frameTimer.getElapsedSeconds();
		if (delta_time >= frame_delay) {
			IterateGameLoop();
			frameTimer.getElapsedSeconds(true);
		}
		Sleep(1);
	}
}
void idPlatformerGame::IterateGameLoop() {
	int element;
	intVector2_t camera = gameplayDisplay.GetRelativeCoords(intVector2_t(0, 0));
	gameBackground.Draw(display, 0, 0);
	scoreDisplay.Draw(display, score);
	for (int i = 0; i < levely; i++) {
		for (int j = 0; j < levelx; j++) {
			element = structure[j][i];
			if (element != -1) {
				if(gameplayDisplay.InBounds(intVector2_t(j * 8, i * 8),intVector2_t(8,8)))
					structureSprite.Draw(display, j * 8 + camera.x, i * 8 + camera.y, element);
			}
		}
	}
	display.Refresh();
	gameplayDisplay.MoveCameraIfNeeded();
}

idPlatformerGame::~idPlatformerGame() {
	for (int i = 0; i < 32; i++) {
		delete[] structure[i];
	}
	delete[] structure;
}


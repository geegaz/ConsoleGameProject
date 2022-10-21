#include "PlatformerGame.h"

idMarioState marioState;

idPlatformerGame::idPlatformerGame():
gameBackground("resources\\sprites\\gameBackground.txt"),
levelDisplayer(display, mario),
livesCount(0), level(0),levelx(32),levely(10), score(69){
}

void idPlatformerGame::Start() {

	float frame_delay = 1.0f / 120.0f; // delay between frames
	float delta_time = 0.0f; // elapsed time between a frame
	LoadLevel();
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
	intVector2_t camera = levelDisplayer.GetRelativeCoords(intVector2_t(0, 0));
	gameBackground.Draw(display, 0, 0);
	scoreDisplay.Draw(display, score);
	UpdateView();
	display.Refresh();
	levelDisplayer.MoveCameraIfNeeded();
}

idPlatformerGame::~idPlatformerGame() {
	auto i = levelStructure.begin();
	auto end = levelStructure.end();
	while (i != end) {
		delete (*i);
		i++;
	}
}

void idPlatformerGame::LoadLevel() {
	idLevelLoader::LoadLevel("\\resources\\levels\\test.txt", levelx, levely, levelStructure);
}

void idPlatformerGame::UpdateView() {
	levelDisplayer.DrawLevel(levelStructure);
}

void idPlatformerGame::UpdateLogic() {

}
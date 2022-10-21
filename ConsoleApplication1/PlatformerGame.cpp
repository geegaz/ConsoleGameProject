#include "PlatformerGame.h"

idMarioState marioState;
float delta_time;

idPlatformerGame::idPlatformerGame():
gameBackground(".\\resources\\sprites\\gameBackground.txt"),
levelDisplayer(display, mario),
livesCount(0), level(0),levelx(32),levely(10), score(69){
}

void idPlatformerGame::Start() {
	float previous_time = 0.0f;
	float current_time = 0.0f;
	float frame_delay = 1.0f / 60.0f; // delay between frames
	delta_time = 0.0f; // elapsed time between a frame
	LoadLevel();
	frameTimer.getElapsedSeconds(true);
	levelStructure.push_back(&mario);
	while (true) {
		delta_time += current_time - previous_time;
		previous_time = current_time;
		if (delta_time >= frame_delay) {	
			IterateGameLoop();
			delta_time = 0;
		}
		current_time = frameTimer.getElapsedSeconds();
	}
}

void idPlatformerGame::IterateGameLoop() {
	int element;
	intVector2_t camera = levelDisplayer.GetRelativeCoords(intVector2_t(0, 0));
	gameBackground.Draw(display, 0, 0);
	scoreDisplay.Draw(display, score);
	UpdateLogic();
	UpdateView();
	display.Refresh();
	levelDisplayer.MoveCameraIfNeeded(); // move camera
}

idPlatformerGame::~idPlatformerGame() {
	levelStructure.pop_back(); // remove mario
	auto i = levelStructure.begin();
	auto end = levelStructure.end();
	while (i != end) {
		delete (*i);
		i++;
	}
}

void idPlatformerGame::LoadLevel() {
	idLevelLoader::LoadLevel(".\\resources\\levels\\test.txt", levelx, levely, levelStructure);
}

void idPlatformerGame::UpdateView() {
	levelDisplayer.DrawLevel(levelStructure);
}

void idPlatformerGame::UpdateLogic() {
	UpdatePhysics();
}

void idPlatformerGame::UpdatePhysics() {

}
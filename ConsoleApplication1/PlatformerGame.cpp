#include "PlatformerGame.h"

idMarioState marioState;
float delta_time;

idSprite idPlatformerGame::OVERWORLD_BACKGROUND(".\\resources\\sprites\\gameBackground.txt");

idPlatformerGame::idPlatformerGame() :
	gameBackground(OVERWORLD_BACKGROUND), levelDisplayer(display, mario),
	livesCount(3), level(0), levelx(32), levely(10), score(69), started(false),
	scoreDisplay(3, 0, 1), coinsCountDisplay(2, 50, 1),
	livesCountDisplay(1, 70, 35),livesIconSprite(SPRITES_PATH+"livesCount.txt"), livesIcon(livesIconSprite) {
}

void idPlatformerGame::Start() {
	float previous_time = 0.0f;
	float current_time = 0.0f;
	float frame_delay = 1.0f / 60.0f; // delay between frames
	delta_time = 0.0f; // elapsed time between a frame
	LoadLevel();
	frameTimer.getElapsedSeconds(true);
	levelStructure.push_back(&mario);
	ShowLifeScreen();
	while (true) {
		inputManager.CheckKeyInputs();
		delta_time += current_time - previous_time;
		previous_time = current_time;
		if (delta_time >= frame_delay) {	
			Update();
			delta_time = 0;
		}
		Sleep(1);
		current_time = frameTimer.getElapsedSeconds();
	}
}

void idPlatformerGame::Update() {
	inputManager.UpdateStates();
	UpdateLogic();
	UpdateView();
	display.Refresh();
	levelDisplayer.MoveCameraIfNeeded(); // move camera
}

void idPlatformerGame::ShowLifeScreen() {
	display.Fill(BLACK);
	livesIcon.Draw(display, intVector2_t(54, 33));
	livesCountDisplay.Draw(display, livesCount);
	display.Refresh();
	Sleep(3000);
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
	gameBackground.Draw(display);
	levelDisplayer.DrawLevel(levelStructure);
	scoreDisplay.Draw(display, score);
}

void idPlatformerGame::UpdateLogic() {
	UpdatePhysics();
}

void idPlatformerGame::UpdatePhysics() {

}
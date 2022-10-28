#include "Snake.h"

float delta_time = 0.0f;

idSnake::idSnake() :
    size(BASE_SIZE),
    headPosition(0, 0),
    gameOver(true),
    logicDelay(0.5f), logicTimer(0.0f),
    gameBackground(SPRITES_PATH + "SnakeBackground.txt"),
    snakeSprite(SPRITES_PATH + "SnakeSprite.txt"),
    appleSprite(SPRITES_PATH + "AppleSprite.txt"),
    titleScreen(SPRITES_PATH + "title_screen.txt"),
    pressSpacePrompt(SPRITES_PATH + "press_space_start.txt"),
    gameOverBackground(SPRITES_PATH + "GameOverBackground.txt"),
    gameOverText(SPRITES_PATH + "GameOver.txt"),
    deadSprite(DARK_GRAY, 4, 4),
    scoreDisplay(3, 1, 1), gameOverScoreDisplay(3, 60, 39), frameDelay(1.0f / 60.0f),
    controlsManager(inputManager), direction(control_t::RIGHT), nextDirection(control_t::RIGHT){
    map = new int[MAP_HEIGHT * MAP_WIDTH];
}

idSnake::~idSnake() {
	delete[] map;
}

void idSnake::Start() {
    timer.start();

    // title screen
    controlsManager.SetState(gameState_t::MENU);
    LoopTitle();

    srand(time(NULL)); // set seed for the game's random apple placement

    while (true) {
        //
        controlsManager.SetState(gameState_t::IN_GAME);
        LoopGame();

        // game over screen
        controlsManager.SetState(gameState_t::MENU);
        LoopDeath();
        LoopGameOver();
    }
}

void idSnake::LoopTitle() {
    titleScreen.Draw(display, 0, 0);
    display.Refresh();
    bool start_pressed = false;
    soundManager.PlayMusicTrack(musicTrack_t::TITLE);
    while (!start_pressed) {
        inputManager.CheckKeyInputs();
        inputManager.UpdateStates();
        if (controlsManager.GetControlState(control_t::START).pressed)
            start_pressed = true;
        titleScreen.Draw(display, 0, 0);
        DisplayStartPrompt();
        display.Refresh();
        Sleep(1);
    }
    soundManager.PlaySoundTrack(soundTrack_t::START);
    soundManager.PlayMusicTrack(musicTrack_t::NONE);
}

void idSnake::LoopGame() {
    particlesManager.Clear();
    delta_time = 0.0f; // elapsed time between a frame
    float previous_time = 0.0f;
    float current_time = 0.0f;
    logicTimer = 0.0f;
    timer.getElapsedSeconds(true);
    Initialize(); // initialize snake game
    DrawGame(display);
    soundManager.PlayMusicTrack(musicTrack_t::IN_GAME);
    // main game screen
    while (!gameOver) {
        delta_time += current_time - previous_time;
        logicTimer += current_time - previous_time;
        previous_time = current_time;
        inputManager.CheckKeyInputs();
        if (delta_time >= frameDelay) {
            inputManager.UpdateStates();
            CheckInputs();
            if (logicTimer >= logicDelay) {
                Update();
            }
            DrawGame(display);
            particlesManager.DrawParticles(display);
            particlesManager.UpdateParticles();

            scoreDisplay.Draw(display, Score());

            display.Refresh();
            delta_time -= frameDelay;
        }
        current_time = timer.getElapsedSeconds();
        Sleep(1);
    }
    soundManager.PlayMusicTrack(musicTrack_t::NONE);
}

void idSnake::LoopDeath() {
    delta_time = 0.0f; // elapsed time between a frame
    float previous_time = 0.0f;
    float current_time = 0.0f;
    timer.getElapsedSeconds(true);

    float length = (float)size;
    float death_time = 1.0f + length * 0.2f;
    float step = death_time / length;

    DrawGameOver(display);
    display.Refresh();

    soundManager.PlaySoundTrack(soundTrack_t::DEATH);
    soundManager.PlaySoundTrack(soundTrack_t::SNAAKE);

    while (death_time > -1.0f) {
        delta_time += current_time - previous_time;
        previous_time = current_time;

        if (delta_time >= frameDelay) {
            death_time -= delta_time;
            if (length > 0.0f && death_time / step < length) {
                CreateDeathEffect();
                length--;
            }

            DrawGameOver(display);
            particlesManager.DrawParticles(display);
            particlesManager.UpdateParticles();

            display.Refresh();

            delta_time -= frameDelay;
        }
        current_time = timer.getElapsedSeconds();
        Sleep(1);
    }
}

void idSnake::LoopGameOver() {
    bool start_pressed = false;
    delta_time = 0.0f; // elapsed time between a frame
    float previous_time = 0.0f;
    float current_time = 0.0f;
    timer.getElapsedSeconds(true);
    
    soundManager.PlayMusicTrack(musicTrack_t::DEATH);
    DisplayStartPrompt(true);
    display.Refresh();
    while (!start_pressed) {
        delta_time += current_time - previous_time;
        previous_time = current_time;
        inputManager.CheckKeyInputs();
        if (delta_time >= frameDelay) {
            inputManager.UpdateStates();
            if (controlsManager.GetControlState(control_t::START).pressed)
                start_pressed = true;
            
            DrawGameOver(display);
            particlesManager.DrawParticles(display);

            gameOverBackground.Draw(display, 0, UI_HEIGHT);
            gameOverText.Draw(display, 29, 15);
            gameOverScoreDisplay.Draw(display, Score());
            appleSprite.Draw(display, 53, 40);
            
            DisplayStartPrompt();
            display.Refresh();
            
            delta_time -= frameDelay;
        }
        current_time = timer.getElapsedSeconds();
        Sleep(1);
    }
    soundManager.PlayMusicTrack(musicTrack_t::NONE);
}
void idSnake::DisplayStartPrompt(bool reset) {
    static bool display_prompt;
    if (reset) {
        display_prompt = true;
        timer.getElapsedSeconds(true);
    }
    if (display_prompt)
        pressSpacePrompt.Draw(display, 10, 55);
    if (timer.getElapsedSeconds() >= 0.75) {
        display_prompt = !display_prompt;
        timer.getElapsedSeconds(true);
    }
}

void idSnake::Initialize() {
	gameOver = false;
	size = BASE_SIZE;
	for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH; i++)
		map[i] = 0;
	int center_x = MAP_WIDTH / 2, center_y = MAP_HEIGHT / 2;
	map[TO_INDEX(center_x, center_y)] = size;
	headPosition.x = center_x;
	headPosition.y = center_y;
	logicDelay = 0.4f;
	GenerateFood();
    direction = control_t::RIGHT;
    nextDirection = control_t::RIGHT;
}

void idSnake::GenerateFood() {
	bool placed = false;
	while (!placed) {
		int ypos = rand() % MAP_HEIGHT, xpos = rand() % MAP_WIDTH;
		if (map[TO_INDEX(xpos, ypos)] == 0) {
			map[TO_INDEX(xpos, ypos)] = APPLE_TILE;
			placed = true;
		}
	}
}

void idSnake::CreateDeathEffect() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            int tile = map[TO_INDEX(j, i)];
            if (tile > 0) {
                if (tile == 1) {
                    particlesManager.CreateDeathParticles(j * SPRITE_SIZE, i * SPRITE_SIZE + UI_HEIGHT, 4);
                }
                map[TO_INDEX(j, i)] -= 1;
            }
        }
    }
}

void idSnake::DrawGame(idDisplay& display) {
    display.Fill(BLACK);
    gameBackground.Draw(display, 0, UI_HEIGHT);
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			int tile = map[TO_INDEX(j, i)];
			if (tile>0) {
				snakeSprite.Draw(display, j * SPRITE_SIZE, i * SPRITE_SIZE + UI_HEIGHT);
			}
			else
				if (tile == APPLE_TILE) {
					appleSprite.Draw(display, j * SPRITE_SIZE, i * SPRITE_SIZE + UI_HEIGHT);
				}
		}
	}
}

void idSnake::DrawGameOver(idDisplay& display) {
    display.Fill(BLACK);
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            int tile = map[TO_INDEX(j, i)];
            if (tile > 0) {
                deadSprite.Draw(display, j * SPRITE_SIZE, i * SPRITE_SIZE + UI_HEIGHT);
            }
        }
    }
}

void idSnake::Update() {
	logicTimer -= logicDelay;
    intVector2_t next = headPosition+NextMove();
    inputManager.CheckKeyInputs();
	if (!gameOver) {
		if (next.x < 0 || next.x >= MAP_WIDTH || next.y < 0 || next.y >= MAP_HEIGHT) {
			gameOver = true;
			return;
		}
		int destination_index = TO_INDEX(next.x, next.y);
		if (map[destination_index] != APPLE_TILE) {
            if (map[destination_index] > 1) {
                gameOver = true;
                return;
            }
			for (int i = 0; i < MAP_HEIGHT; i++) {
				for (int j = 0; j < MAP_WIDTH; j++) {
					if (map[TO_INDEX(j, i)] > 0)
						map[TO_INDEX(j, i)]--;
				}
			}
			map[destination_index] = size;
            headPosition = next;
		}
		else {
			size++;
            particlesManager.CreateAppleCollectEffect(next.x * SPRITE_SIZE, next.y * SPRITE_SIZE + UI_HEIGHT);
            soundManager.PlaySoundTrack(soundTrack_t::COLLECT);
			map[destination_index] = size;
            headPosition = next;
			if (logicDelay > 0.03f)
				logicDelay*=0.95f;
			GenerateFood();
		}
	}
}

intVector2_t idSnake::NextMove() {
	intVector2_t next;
    direction = nextDirection;
	switch (direction) {
	case control_t::RIGHT:
		next.x = 1;
		break;
	case control_t::LEFT:
		next.x = -1;
		break;
	case control_t::UP:
		next.y = -1;
		break;
	case control_t::DOWN:
		next.y = 1;
		break;
	default:
		break;
	}
	return next;
}

void idSnake::CheckInputs() {
    if (controlsManager.GetControlState(control_t::DOWN).pressed) {
        ChangeDirection(control_t::DOWN);
        return;
    }
    if (controlsManager.GetControlState(control_t::LEFT).pressed) {
        ChangeDirection(control_t::LEFT);
        return;
    }
    if (controlsManager.GetControlState(control_t::RIGHT).pressed) {
        ChangeDirection(control_t::RIGHT);
        return;
    }
    if (controlsManager.GetControlState(control_t::UP).pressed) {
        ChangeDirection(control_t::UP);
        return;
    } 
}

void idSnake::ChangeDirection(control_t newDirection) {
	switch (direction) {
	case control_t::RIGHT:
		if (newDirection == control_t::LEFT)
			return;
		break;
	case control_t::LEFT:
		if (newDirection == control_t::RIGHT)
			return;
		break;
	case control_t::UP:
		if (newDirection == control_t::DOWN)
			return;
		break;
	case control_t::DOWN:
		if (newDirection == control_t::UP)
			return;
		break;
	default:
		return;
		break;
	}
	nextDirection = newDirection;
}
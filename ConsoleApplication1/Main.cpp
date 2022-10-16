#include <windows.h>
#include <iostream>
#include <string>
#include "NYTimer.h"
#include "Display.h"
#include "Sprite.h"
#include "Snake.h"
#include "InputManager.h"
#include "ControlsManager.h"
#include "ScoreDisplay.h"
#include "PhysicsTest.h"
#include "SoundUtils.h"
#include "SoundManager.h"
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Xinput.lib")
#pragma comment(lib, "OpenAL32.lib")
using namespace std;

int main()
{
    //--- Engine setup

    float delta = 0.0f;
    float frame_delay = 1.0f / 30.0f;
    
    idDisplay display;
    idInputManager input;
    idControlsManager controls(input);
    //idSoundManager sound; // makes everything crash
    NYTimer time;

    //--- Game setup

    idPhysicsTest game(display, controls);

    //--- Main loop

    time.start();
    display.Fill(BLACK);
    while (true) {
        input.CheckKeyInputs();

        delta = time.getElapsedSeconds();
        if (delta >= frame_delay) {
            display.Fill(BLACK);
            input.UpdateStates();

            game.Update(delta);

            display.Refresh();
            time.getElapsedSeconds(true);
        }
        Sleep(1);
    }

    //const float frame_delay = 1.0f / 30.0f; // delay between frames
    //float delta_time = 0.0f; // elapsed time between a frame
    //float previous = 0.0f; // storage for previous delta_time
    //bool started = false;
    //bool display_prompt = true;

    //idDisplay display;
    //NYTimer frame_timer;
    //idInputManager input_manager;

    //// add SPACE keyboard key for the title screen
    //input_manager.AddKey(' ');

    //// load sprites
    //idSprite snake_background("resources\\sprites\\SnakeBackground.txt");
    //idSprite snake_sprite("resources\\sprites\\SnakeSprite.txt"), apple_sprite("resources\\sprites\\AppleSprite.txt");
    //idSprite title_screen("resources\\sprites\\title_screen.txt");
    //idSprite press_space("resources\\sprites\\press_space.txt");
    //idSprite game_over_background("resources\\sprites\\GameOverBackground.txt");
    //idSprite game_over_text("resources\\sprites\\GameOver.txt");
    //idSprite numbers_sprite("resources\\sprites\\Numbers.txt");

    //// initialize score display
    //idScoreDisplay snakeScoreDisplay(numbers_sprite);

    //// initialize snake game
    //idSnake snake(snake_sprite, apple_sprite);

    //frame_timer.start();

    //title_screen.Draw(display, 0, 0);
    //display.Refresh();

    //// title screen
    //while (!started) {
    //    // check if the user pressed SPACE and make text flash
    //    input_manager.UpdateKeys();
    //    if (input_manager.lastKey == ' ') {
    //        started = true;
    //    }
    //    if (frame_timer.getElapsedSeconds() >= 0.5) {
    //        display_prompt = !display_prompt;
    //        title_screen.Draw(display, 0, 0);
    //        if (display_prompt) {
    //            press_space.Draw(display, 19, 59);
    //            Beep(DWORD(500), DWORD(250));
    //        }
    //        display.Refresh();
    //        frame_timer.getElapsedSeconds(true);
    //    }
    //}
    //srand(time(NULL)); // set seed for the game's random apple placement
    //while(true){
    //    frame_timer.getElapsedSeconds(true);
    //    // add ZQSD as possible keys for inputs
    //    input_manager.AddKey('Z');
    //    input_manager.AddKey('Q');
    //    input_manager.AddKey('S');
    //    input_manager.AddKey('D');
    //    // remove spacebar as input
    //    input_manager.RemoveKey(' ');
    //    
    //    display.Fill(BLACK);
    //    snake_background.Draw(display, 0, UI_HEIGHT); // draw background for game
    //    snake.Start(); // initialize snake game
    //    snake.DrawGame(display);
    //    // main game screen
    //    while (!snake.IsGameOver()) {
    //        previous = delta_time;
    //        delta_time = frame_timer.getElapsedSeconds();
    //        snake.Forward(delta_time - previous);
    //        input_manager.UpdateKeys();
    //        if (delta_time >= frame_delay) {
    //            if (snake.CanMove()) {
    //                // check player's inputs and move snake
    //                switch (input_manager.lastKey) {
    //                case 'Z':
    //                    snake.ChangeDirection(UP);
    //                    break;
    //                case 'Q':
    //                    snake.ChangeDirection(LEFT);
    //                    break;
    //                case 'S':
    //                    snake.ChangeDirection(DOWN);
    //                    break;
    //                case 'D':
    //                    snake.ChangeDirection(RIGHT);
    //                    break;
    //                }
    //                snake.Update();
    //            }
    //            display.Fill(BLACK);
    //            snake_background.Draw(display, 0, UI_HEIGHT);
    //            snake.DrawGame(display);

    //            snakeScoreDisplay.Draw(display, snake.Score());

    //            display.Refresh();
    //            delta_time = previous = 0.0f;
    //            frame_timer.getElapsedSeconds(true);
    //        }
    //    }
    //    
    //    PlaySound(L".\\resources\\sounds\\death_goldenberry.wav", NULL, SND_ASYNC);
    //    started = false;
    //    // remove ZQSD inputs after Game Over
    //    input_manager.RemoveKey('Z');
    //    input_manager.RemoveKey('Q');
    //    input_manager.RemoveKey('S');
    //    input_manager.RemoveKey('D');
    //    // restore spacebar as input
    //    input_manager.AddKey(' ');
    //    frame_timer.getElapsedSeconds(true);
    //    display_prompt = true;
    //    game_over_background.Draw(display, 0, UI_HEIGHT);
    //    game_over_text.Draw(display, 29, 20);
    //    press_space.Draw(display, 19, 59);
    //    display.Refresh();
    //    // game over screen
    //    while (!started) {
    //        // check if the user pressed SPACE and make text flash
    //        input_manager.UpdateKeys();
    //        if (input_manager.lastKey == ' ') {
    //            started = true;
    //        }
    //        if (frame_timer.getElapsedSeconds() >= 0.5) {
    //            display_prompt = !display_prompt;
    //            snake_background.Draw(display, 0, UI_HEIGHT);
    //            snake.DrawGame(display);
    //            game_over_background.Draw(display, 0, UI_HEIGHT);
    //            game_over_text.Draw(display, 29, 20);
    //            if (display_prompt) {
    //                press_space.Draw(display, 19, 59);
    //                Beep(DWORD(500), DWORD(250));
    //            }   
    //            display.Refresh();
    //            frame_timer.getElapsedSeconds(true);
    //        }
    //    }
    //}
    
}